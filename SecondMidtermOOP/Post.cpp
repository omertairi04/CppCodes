#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Post {
protected:
	string username;
	string content;
	bool hasPhoto;
	int likes;
public:
	Post(const string &username, const string &content, bool has_photo, int likes)
		: username(username),
		  content(content),
		  hasPhoto(has_photo),
		  likes(likes) {
	}

	virtual double popularity() = 0;
	virtual void print() = 0;

	bool operator<(Post &rhs) {
		return popularity() < rhs.popularity();
	}

	bool operator<=(Post &rhs) {
		return !(rhs < *this);
	}

	bool operator>(Post &rhs) {
		return rhs < *this;
	}

	bool operator>=(Post &rhs) {
		return !(*this < rhs);
	}

	bool getHasPhoto() {
		return this->hasPhoto;
	}

	~Post() {}
};

class FacebookPost: public Post {
	int shares;
public:
	FacebookPost(const string &username, const string &content, bool has_photo, int likes, int shares)
		: Post(username, content, has_photo, likes),
		  shares(shares) {
	}

	double popularity() override {
		int popularity = likes * shares;

		if (hasPhoto) popularity *= 1.20;

		return popularity;
	};

	void print() override {
		// cout << "Popularity: " << popularity() << endl;
		cout << "Facebook Post" << endl;
		cout << "Username: " << username << endl;
		cout << "Content: " << content << endl;
		if (hasPhoto) cout << "With photo" << endl;
		cout << "Likes: " << likes << " Shares: " << shares << endl;
		cout << "Popularity: " << popularity() << endl;
	};
};

class TwitterPost : public Post {
	int retweets;
	int replies;
public:
	TwitterPost(const string &username, const string &content, bool has_photo, int likes, int retweets, int replies)
		: Post(username, content, has_photo, likes),
		  retweets(retweets),
		  replies(replies) {
	}

	double popularity() override {
		int popularity = likes * retweets * replies;

		if (hasPhoto) popularity *= 1.10;

		if (content.find("#crypto") != -1) {
			popularity *= 1.20;
		}

		return popularity;
	};

	void print() override {
		// cout << "Popularity: " << popularity() << endl;
		cout << "Twitter Post" << endl;
		cout << "Username: " << username << endl;
		cout << "Content: " << content << endl;
		if (hasPhoto) cout << "With photo" << endl;
		cout << "Likes: " << likes << " Retweets: " << retweets << " Replies: " << replies << endl;
		cout << "Popularity: " << popularity() << endl;
	};
};

double mostPopularPostWithPhoto(Post **posts, int n) {
	double max = -1;

	for (int i=0;i<n;i++) {
		if (posts[i]->getHasPhoto()) {
			max = posts[i]->popularity();
			break;
		}
	}

	for (int i=0;i<n;i++) {
		if (posts[i]->getHasPhoto()) {
			if (posts[i]->popularity() > max) {
				max = posts[i]->popularity();
			}
		}
	}

	return max;

}

Post *readFbPost() {
	string username;
	string content;
	bool photo;
	int likes;
	int shares;
	cin.ignore();
	getline(std::cin, username);
	getline(std::cin, content);
	cin >> photo >> likes >> shares;
	return new FacebookPost(username, content, photo, likes, shares);
}

Post *readTwPost() {
	string username;
	string content;
	bool photo;
	int likes;
	int retweets;
	int replies;
	cin.ignore();
	getline(std::cin, username);
	getline(std::cin, content);
	cin >> photo >> likes >> retweets >> replies;
	return new TwitterPost(username, content, photo, likes, retweets, replies);
}

Post **readMultiplePosts(int *n) {

	cin >> *n;
	Post **posts = new Post *[*n];
	for (int i = 0; i < *n; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			posts[i] = readFbPost();
		} else {
			posts[i] = readTwPost();
		}
	}
	return posts;
}
//
// int main() {
// 	int testCase;
//
// 	cin >> testCase;
//
// 	if (testCase == 1) {
// 		cout << "Test FacebookPost" << endl;
// 		Post *post = readFbPost();
// 		cout << "Popularity: " << post->popularity() << endl;
// 		post->print();
// 	} else if (testCase == 2) {
// 		cout << "Test TwitterPost" << endl;
// 		Post *post = readTwPost();
// 		cout << "Popularity: " << post->popularity() << endl;
// 		post->print();
// 	} else if (testCase == 3) {
// 		cout << "Test operator >=" << endl;
// 		int n;
// 		Post **posts = readMultiplePosts(&n);
//
// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < n; j++) {
// 				if (i != j) {
// 					if ((*posts[i]) >= (*posts[j])) {
// 						cout << i << " >= " << j << endl;
// 					} else {
// 						cout << i << " < " << j << endl;
// 					}
// 				}
// 			}
// 		}
// 	} else {
// 		int n;
// 		Post **posts = readMultiplePosts(&n);
// 		for (int i = 0; i < n; i++) {
// 			posts[i]->print();
// 			cout << endl;
// 		}
// 		cout << "The most popular post with photo has a popularity of: " << mostPopularPostWithPhoto(posts, n) << endl;
// 		// cout << "The facebook post with most shares is ";
// 		// fbPostWithMaxShares(posts,n)->print();
// 	}
//
// 	return 0;
// }

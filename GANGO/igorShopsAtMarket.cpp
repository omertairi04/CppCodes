/* Igor wants to make a fruit salad. To do that, he goes to the market where the
   prices are as follows:

      The price of 100 grams of apples is 30 denars, the price of 100 grams of
   raspberries is 50 denars, and the price of 100 grams of bananas is 40 denars.

      If he buys 200 grams of one type of fruit (apples/raspberries/bananas), he
   gets a 30% discount, and if he buys 500 grams or more of one type of fruit,
   he gets a 50% discount. (Example: He will get a discount if he buys 500 grams
   of just raspberries, not a total of 500 grams from all fruits)

      Additionally: When paying, we check if Igor wants to use 140 denars from
   his daily student meal card.

      If YES, 140 denars are subtracted from the total amount; otherwise, the
   amount remains unchanged. How much money does Igor need to pay extra?

      Explanation of input parameters:
      We have how many grams he wants to buy of each fruit, respectively in the
   order apples, raspberries, bananas, and 1 or 0 depending on whether he wants
   to pay 140 denars with his student card or not. */

#include <iostream>

int main() {
  int apples, raspberries, bananas;
  double total;

  std::cin >> apples >> raspberries >> bananas;

  double applePrice = apples * 0.3;
  double raspberriesPrice = raspberries * 0.5;
  double bananaPrice = bananas * 0.4;

  // can Igor get the 30% discout
  if (apples >= 200) {
    applePrice -= applePrice * 0.3;
  }

  if (raspberries >= 200) {
    raspberriesPrice -= raspberriesPrice * 0.3;
  }

  if (bananas >= 200) {
    bananaPrice -= bananaPrice * 0.3;
  }

  // check if Igor can get 50 % discount
  if (apples >= 500) {
    applePrice -= applePrice * 0.5;
  }

  if (raspberries >= 500) {
    raspberriesPrice -= raspberriesPrice * 0.5;
  }

  if (bananas >= 500) {
    bananaPrice -= bananaPrice * 0.5;
  }

  bool usesStudentsCard;
  std::cin >> usesStudentsCard;

  total = applePrice + raspberriesPrice + bananaPrice;

  if (usesStudentsCard) {
    total -= 140;
  }
  std::cout << total << "\n";
}

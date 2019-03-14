//
// Created by Casper Skjærris on 2019-03-06.
//

#ifndef FINANCESIMULATOR_ORDERSLIP_H
#define FINANCESIMULATOR_ORDERSLIP_H

enum TransactionType{
    Buy,Sell
};

enum OrderStatus{
    Recieved, Processed, Finished
};

struct OrderSlip{
    TransactionType buyOrSell;
    int traderId;
    int securityOrdered;
    double limitPrice;
    int amountToDo;
    OrderStatus orderStatus;

};


#endif //FINANCESIMULATOR_ORDERSLIP_H

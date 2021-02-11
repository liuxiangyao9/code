#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    /*
     * res:总收入
     * single:单注
     * money:起始资金
     * moudleTimes:模型运行次数
     * */
    double res = 0;
    int single = 3;
    int money = 50;
    int moudleTimes = 100;
    double onePercent = 100.00 / moudleTimes;
    double winPercent = 0, losePercent = 0, loseAllPercent = 0, cantPercent = 0;

    srand((unsigned int)time(NULL));

    for (int moudle = 0; moudle < moudleTimes; moudle++) {

	/*
	 * balance:当前模型余额
	 * balanceCopy:模型起始余额
	 * */
	double balance = money;
	double balanceCopy = balance;

	for (int i = 0; i < 30; i++) {

	    int n1 = (rand() % 10) + 1;
	    int n2 = (rand() % 10) + 1;
	    int n3 = (rand() % 10) + 1;

	    balanceCopy = balance;
	    balance -= single * 3;
	    if (n1 % 2)
		balance += single * 1.98;
	    if (n2 % 2)
		balance += single * 1.98;
	    if (n3 % 2)
		balance += single * 1.98;

	    // printf("round:%d---balance:%.2f|%.2f---%d-%d-%d\n", i + 1, balance,balance - balanceCopy, n1, n2, n3);
	    
	    // 结算输光和下不起注概率
	    if (balance <= 0) {
		loseAllPercent += onePercent;
		break;
	    }
	    if (balance / 3 < single) {
		cantPercent += onePercent;
		break;
	    }
	}

	// 总收入
	res += balance;
	
	// 结算盈亏概率
	if (balance > money)
	    winPercent += onePercent;
	if (balance < money)
	    losePercent += onePercent;

	// 每轮结束后输出余额balance
	printf("balance:%.2f\n", balance);

    }

    // 输出总支出与总收入，以及各类概率
    printf("\nin:%2.d---out:%.2f\n", money * moudleTimes, res);
    printf("win:%.2f---lose:%.2f---loseAll:%.2f---cant:%.2f\n", winPercent, losePercent, loseAllPercent, cantPercent);

    return 0;
}

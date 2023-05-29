#include "DrinkCondoleApp.h"
#include "DrinkItem.h"
#include "OrderItem.h"

int main()
{
	vector<DrinkItem> drinks;
	vector<OrderItem> order;

	//�s�W���ƫ~��
	AddNewDrink(drinks);

	//��ܩҦ����Ƶ��
	DisplayDrinkMenu(drinks);

	//�I�\
	OrderDrink(order, drinks);

	//�p���`���B�P���
	CalculateSalePrice(order, drinks);

	return 0;
}

void AddNewDrink(vector<DrinkItem>& drinks)
{
	//DrinkItem drink1("����", "�j�M", 60);
	//drinks.push_back(drink1);
	//DrinkItem drink2("����", "�p�M", 40);
	//drinks.push_back(drink2);

	drinks.push_back(DrinkItem("����", "�j�M", 60));
	drinks.push_back(DrinkItem("����", "�p�M", 40));
	drinks.push_back(DrinkItem("���", "�j�M", 60));
	drinks.push_back(DrinkItem("���", "�p�M", 40));
	drinks.push_back(DrinkItem("�@��", "�j�M", 80));
	drinks.push_back(DrinkItem("�@��", "�p�M", 50));
	drinks.push_back(DrinkItem("�i��", "�j�M", 30));
	drinks.push_back(DrinkItem("�i��", "�p�M", 20));
}

void DisplayDrinkMenu(vector<DrinkItem>& drinks) {
	cout << setw(4) << "�s��" << setw(10) << "���ƦW��" << setw(10) << "�j�p" << setw(10) << "���" << endl;
	cout << "--------------------------------------" << endl;

	int i = 1;
	//for (DrinkItem item : drinks) {
	//    cout << setw(4) << i;
	//    item.displayItem();
	//    i++;
	//}

	//vector<DrinkItem>::iterator v = drinks.begin();
	//while (v != drinks.end()) {
	//    cout << setw(4) << i;
	//    v->displayItem();
	//    v++;
	//    i++;
	//}

	for (int j = 0; j < drinks.size(); j++) {
		cout << setw(4) << i;
		drinks[j].displayItem();
		i++;
	}
	cout << "--------------------------------------" << endl;
	cout << "�`�@��" << drinks.size() << "�Ӷ��ƫ~��" << endl;
}

void OrderDrink(vector<OrderItem>& order, vector<DrinkItem>& drinks) {
	//cout << "�}�l�q�ʶ���" << endl;
	int index;
	int qty;
	char ans = 'Y';

	do {
		cout << "�п�J�n�q�ʪ����ƽs���G ";
		cin >> index;
		cout << "�п�J�n�q�ʪ����Ƽƶq�G ";
		cin >> qty;

		if (index < 1 || index>drinks.size()) {
			cout << "��J���ƫ~���s�����~�A�Э��s��J�I" << endl;
		}
		else if (qty < 1) {
			cout << "��J���Ƽƶq���~�A�Э��s��J�I" << endl;
		}
		else {
			OrderItem orderitem = OrderItem(index, qty);
			order.push_back(orderitem);
			orderitem.displayOrderItem(drinks);
			cout << "�O�_�~���I�\�H(Y��y���~��q�\)";
			cin >> ans;
		}
	} while (ans == 'Y' || ans == 'y');
}

void CalculateSalePrice(vector<OrderItem>& order, vector<DrinkItem>& drinks) {
	//cout << "�p�ⶼ�ư��" << endl;
	int takeIn = 1;
	cout << "�аݬO�����٬O�~�a�H(1:���� 2:�~�a): ";
	cin >> takeIn;
	string messageTakeIn = (takeIn == 1) ? "����" : "�~�a";

	int totalPrice = 0;
	int salePrice = 0;
	string messagePrice = "";
	cout << "---------------------------------" << endl;
	cout << "�z���I�����Ʀp�U�G" << endl;
	cout << "---------------------------------" << endl;
	for (OrderItem orderitem : order) {
		orderitem.displayOrderItem(drinks);
		DrinkItem drinkitem = drinks[orderitem.getIndex() - 1];
		totalPrice += drinkitem.getPrice() * orderitem.getQuantity();
	}

	if (totalPrice >= 500) {
		salePrice = totalPrice * 0.8;
		messagePrice = "�q�ʺ�500���H�W��8��";
	}
	else if (totalPrice >= 300) {
		salePrice = totalPrice * 0.85;
		messagePrice = "�q�ʺ�300���H�W��85��";
	}
	else if (totalPrice >= 200) {
		salePrice = totalPrice * 0.9;
		messagePrice = "�q�ʺ�200���H�W��9��";
	}
	else {
		salePrice = totalPrice;
		messagePrice = "�q�ʥ���200��������";
	}

	cout << "---------------------------------" << endl;
	cout << "�q�ʤ覡�G " << messageTakeIn << endl;
	cout << "�`���B�G " << totalPrice << endl;
	cout << messagePrice << endl;
	cout << "����G " << salePrice << endl;
	cout << "---------------------------------" << endl;
}

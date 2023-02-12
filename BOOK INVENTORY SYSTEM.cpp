#include<iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<ctime>
using namespace std;

fstream file;
fstream file2;
fstream file3;
fstream file4;
fstream file5;

int choice[5];
time_t t = time(0);
char* dt = ctime(&t);
tm *ltm = localtime(&t);

login_display()
{
	char A[32]="Login Successful, Welcome Back!";
	cout << "\n\n\t\t\t";
	for(int i=0;i<31;i++)
	{
		cout << A[i];
		Sleep(50);
	}
	Sleep(700);
}

display_books()
{
	string title,author,publisher;
	int price,stock;
	file.open("TITLE.txt");
	file2.open("AUTHOR.txt");
	file3.open("PUBLISHER.txt");
	file4.open("PRICE.txt");
	file5.open("STOCK.txt");
	while(!file.eof())
	{
		getline(file,title);
		getline(file2,author);
		getline(file3,publisher);
		file4 >> price;
		file5 >> stock;
		if(stock != 0)
		{
			cout << "\t\t\tTitle:     " << title << "\n\t\t\tAuthor:    " << author << "\n\t\t\tPublisher: " << publisher << "\n\t\t\tPrice:     " << price << " RS\n\t\t\tStock:     " << stock << "\n\n";
		}
	}
	file.close();
	file2.close();
	file3.close();
	file4.close();
	file5.close();
}

class Bookshop
{
	public:
		string title[10],author[10],publisher[10],temp,stemp[10],code;
		int price[10],stock[10],itemp[10],i=0,result,discount=0;
		homescreen()
		{
			system("cls");
			cout << "\t\t\t============\n\t\t\t HOMESCREEN\n\t\t\t============";
			cout << "\n\n\t\t\t1. Login";
			cout << "\n\t\t\t2. Available Books"; 
			cout << "\n\t\t\t3. Search Books";
			cout << "\n\t\t\t4. Buy Books";
			cout << "\n\t\t\t5. Exit";
			cout << "\n\n\n\t\t\tEnter choice: ";
			cin >> choice[0];
		}
		books()
		{
			system("cls");
			cout << "\t\t\t=================\n\t\t\t AVAILABLE BOOKS\n\t\t\t=================\n\n";
			display_books();
			cout << "\n\t\t\t- Press any key to return to home screen.";
			getch();
		}
		book_search()
		{
			result = 0,i = 0;
			file.open("TITLE.txt");
			file2.open("AUTHOR.txt");
			file3.open("PUBLISHER.txt");
			file4.open("PRICE.txt");
			file5.open("STOCK.txt");
			system("cls");
			cout << "\t\t\t=============\n\t\t\t BOOK SEARCH\n\t\t\t=============";
			cout << "\n\n\t\t\t1. Search by title\n\t\t\t2. Search by author\n\t\t\t3. Search by publisher\n\t\t\t4. Homescreen";
			cout << "\n\n\n\t\t\tEnter choice: ";
			cin >> itemp[0];
			system("cls");
			cout << "\t\t\t=============\n\t\t\t BOOK SEARCH\n\t\t\t=============";
			if(itemp[0] == 1)
			{
				cin.ignore();
				cout << "\n\n\t\t\tEnter title: ";
				getline(cin,temp);
				cout << "\n\n\t\t\tBooks found:\n\n";
				while(!file.eof())
				{
					getline(file,title[i]);
					getline(file2,author[i]);
					getline(file3,publisher[i]);
					file4 >> price[i];
					file5 >> stock[i];
					if(temp == title[i])
					{
						cout << "\t\t\tTitle:     " << title[i] << "\n\t\t\tAuthor:    " << author[i] << "\n\t\t\tPublisher: " << publisher[i] << "\n\t\t\tPrice:     " << price[i] << " RS\n\t\t\tStock:     " << stock[i] << "\n\n";
						result++;
					}
					i++;
				}
				if(result == 0)
				{
					cout << "\t\t\tNone";
				}
				cout << "\n\n\t\t\t" << result << " results found.";
				cout << "\n\t\t\tPress any key to return.";
				getch();
			}
			else if(itemp[0] == 2)
			{
				cin.ignore();
				cout << "\n\n\t\t\tEnter author: ";
				getline(cin,temp);
				cout << "\n\n\t\t\tBooks found:\n\n";
				while(!file.eof())
				{
					getline(file,title[i]);
					getline(file2,author[i]);
					getline(file3,publisher[i]);
					file4 >> price[i];
					file5 >> stock[i];
					if(temp == author[i])
					{
						cout << "\t\t\tTitle:     " << title[i] << "\n\t\t\tAuthor:    " << author[i] << "\n\t\t\tPublisher: " << publisher[i] << "\n\t\t\tPrice:     " << price[i] << " RS\n\t\t\tStock:     " << stock[i] << "\n\n";
						result++;					
					}
					i++;
				}
				if(result == 0)
				{
					cout << "\t\t\tNone";
				}
				cout << "\n\n\t\t\t" << result << " results found";
				cout << "\n\t\t\tPress any key to return.";
				getch();
			}
			else if(itemp[0] == 3)
			{
				cin.ignore();
				cout << "\n\n\t\t\tEnter publisher: ";
				getline(cin,temp);
				cout << "\n\n\t\t\tBooks found:\n\n";
				while(!file.eof())
				{
					getline(file,title[i]);
					getline(file2,author[i]);
					getline(file3,publisher[i]);
					file4 >> price[i];
					file5 >> stock[i];
					if(temp == publisher[i])
					{
						cout << "\t\t\tTitle:     " << title[i] << "\n\t\t\tAuthor:    " << author[i] << "\n\t\t\tPublisher: " << publisher[i] << "\n\t\t\tPrice:     " << price[i] << " RS\n\t\t\tStock:     " << stock[i] << "\n\n";
						result++;
					}
					i++;
				}
				if(result == 0)
				{
					cout << "\t\t\tNone";
				}
				cout << "\n\n\t\t\t" << result << " results found";
				cout << "\n\t\t\tPress any key to return.";
				getch();
			}
			file.close();
			file2.close();
			file3.close();
			file4.close();
			file5.close();
		}
		invoice(int price)
		{
			file.open("DATE.txt",ios::app);
			file2.open("SALES.txt",ios::app);
			system("cls");
			cout << "\t\t\t=========\n\t\t\t INVOICE\n\t\t\t=========\n\n";
			cout << "\t\t\t-Date and time: " << dt << "\n\t\t\t-Product:   " << temp << "\n\t\t\t-Quantity:  " << itemp[0] << "\n\t\t\t-Total:     " << price << " RS\n\n\t\t\t-Discount:  0 RS\n\t\t\t-Sub total: " << price << " RS";
			file << 1 + ltm->tm_mon << endl;
			file2 << "Date and time: " << dt << "  | Product: " << temp << " | Quantity: " << itemp[0] << " | Total: " << price << " RS | Discount:  0 | Sub total: " << price << " RS" << endl;
			file.close();
			file2.close();
		}
		invoice(int price, int discount)
		{
			file.open("DATE.txt",ios::app);
			file2.open("SALE.txt",ios::app);
			system("cls");
			cout << "\t\t\t=========\n\t\t\t INVOICE\n\t\t\t=========\n\n";
			cout << "\t\t\t-Date and time: " << dt << "\n\t\t\t-Product:   " << temp << "\n\t\t\t-Quantity:  " << itemp[0] << "\n\t\t\t-Total:     " << price << " RS\n\n\t\t\t-Discount:  " << discount << " RS\n\t\t\t-Sub total: " << price - discount << " RS";
			file << 1 + ltm->tm_mon << endl;
			file2 << "Date and time: " << dt << "  | Product: " << temp << " | Quantity: " << itemp[0] << " | Total: " << price << " RS | Discount: " << discount << " RS | Sub total: " << price - discount << " RS" << endl;
			file.close();
			file2.close();
		}
		buy()
		{
			i = 0,result = 0;
			system("cls");
			cout << "\t\t\t==========\n\t\t\t BUY MENU\n\t\t\t==========\n\n";
			cout << "\t\t\tAVAILABLE BOOKS:\n\n";
			display_books();
			cout << "\n\n\t\t\t========================================================================\n";
			cout << "\t\t\t NOTE: Enter title same as shown above with a valid number of quantity.\n";
			cout << "\t\t\t========================================================================\n";
			cout << "\n\t\t\t-Enter the title of the book you want to buy: ";
			cin.ignore();
			getline(cin,temp);
			cout << "\n\t\t\t-Quantity: ";
			cin >> itemp[0];
			cout << "\n\t\t\t-Customer code (0 if you're not a customer): ";
			cin.ignore();
			getline(cin,code);
			file.open("TITLE.txt",ios::in);
			file2.open("CUSTOMER.txt",ios::in);
			file4.open("PRICE.txt",ios::in);
			file5.open("STOCK.txt",ios::in);
			while(!file.eof() && !file5.eof())
			{
				getline(file,title[i]);
				getline(file2,stemp[i]);
				file4 >> price[i];
				file5 >> stock[i];
				if(temp == title[i] && itemp[0] <= stock[i])
				{
					stock[i] = stock[i] - itemp[0];
					itemp[1] = price[i];
					result = 1;
				}
				if(code == stemp[i])
				{
					discount = 1;
				}
				i++;
			}
			file.close();
			file2.close();
			file4.close();
			file5.close();
			if(result == 1)
			{
				file5.open("STOCK.txt",ios::out);
				for(i=0;i<4;i++)
				{
					file5 << stock[i] << endl;
				}
				file5.close();
				if(discount == 0)
				{
					invoice(itemp[1]*itemp[0]);
				}
				else
				{
					invoice(itemp[1]*itemp[0],((itemp[1]*itemp[0])/100)*5);
				}
			}
			else
			{
				cout << "\n\t\t\tInvalid book or quantity entry, press any key to return.";
			}
			getch();
		}
};

class Account
{
	protected:
		int stock[5],itemp,i=0,result,month[2]={0,0};
		string title[5],code[5],pass[5],un[5],stemp[5];
	public:
		add_customer()
		{
			cin.ignore();
			p:
			i = 0, itemp = 0;
			system("cls");
			cout << "\t\t\t===================\n\t\t\t CUSTOMER ADDITION\n\t\t\t===================";
			file.open("CUSTOMER.txt",ios::in);
			cout << "\n\n\t\t\tEnter a customer code to add a customer: ";
			getline(cin,stemp[0]);
			while(!file.eof())
			{
				getline(file,code[i]);
				i++;
			}
			file.close();
			for(i=0;i<5;i++)
			{
				if(stemp[0] == code[i])
				{
					cout << "\n\t\t\tCustomer code already in use, Press any key to retry.";
					getch();
					goto p;
				}
			}
			file.open("CUSTOMER.txt",ios::app);
			file << stemp[0] << endl;
			file.close();
			cout << "\n\t\t\tCustomer " << stemp[0] << " created, Press any key to return.";
			getch();
		}
		del_customer()
		{
			z:
			i = 0, itemp = 0;
			system("cls");
			cout << "\t\t\t==================\n\t\t\t CUSTOMER REMOVAL\n\t\t\t==================";
			file.open("CUSTOMER.txt",ios::in);
			while(!file.eof())
			{
				getline(file,code[i]);
				i++;
			}
			file.close();
			cout << "\n\n\t\t\tEnter customer code to delete customer: ";
			cin >> stemp[0];
			file.open("CUSTOMER.txt",ios::out);
			for(i=0;i<5;i++)
			{
				if(code[i] == "")
				{
					break;
				}
				if(stemp[0] != code[i])
				{
					file << code[i] << endl;
				}
				else
				{
					itemp++;
				}
			}
			file.close();
			if(itemp <= 0)
			{
				cout << "\n\t\t\tNo customer found, Press any key to retry.";
				getch();
				goto z;
			}
			else
			{
				cout << "\n\t\t\tCustomer " << stemp[0] << " deleted, Press any key to return.";
			}
			getch();
		}
		mod_customer()
		{
			cin.ignore();
			retry:
			i = 0, itemp = 0;
			system("cls");
			cout << "\t\t\t==================\n\t\t\t CUSTOMER SETTING\n\t\t\t==================";
			cout << "\n\n\t\t\tEnter current customer code: ";
			getline(cin,stemp[0]);
			cout << "\n\t\t\tEnter new customer code: ";
			getline(cin,stemp[1]);
			file.open("CUSTOMER.txt",ios::in);
			while(!file.eof())
			{
				getline(file,code[i]);
				if(stemp[1] == code[i])
				{
					break;
				}
				if(stemp[0] == code[i])
				{
					code[i] = stemp[1];
					itemp = 1;
				}
				i++;
			}
			file.close();
			if(itemp == 0)
			{
				cout << "\n\t\t\tInvalid customer code please try again.";
				getch();
				goto retry;
			}
			else
			{
				file.open("CUSTOMER.txt",ios::out);
				for(i=0;i<5;i++)
				{
					if(code[i] == "")
					{
						break;
					}
					file << code[i] << endl;
				}
				file.close();
				cout << "\n\t\t\tCustomer code changed, Press any key to return";
			}
			getch();
		}
		stock_check()
		{
			i = 1;
			system("cls");
			cout << "\t\t\t===================\n\t\t\t STOCK INFORMATION\n\t\t\t===================\n\n\t\t\t";
			file.open("TITLE.txt",ios::in);
			file5.open("STOCK.txt",ios::in);
			while(!file.eof() && !file5.eof())
			{
				getline(file,title[0]);
				file5 >> stock[0];
				cout << i << ". Title: " << title[0] << "\n\t\t\t   Stock: " << stock[0] << "\n\n\t\t\t";
				i++;
			}
			file.close();
			file5.close();
			cout << "\n\t\t\t-- Press any key to return.";
			getch();
		}
		add_stock()
		{
			i = 0,result = 0;
			system("cls");
			cout << "\t\t\t================\n\t\t\t STOCK ADDITION\n\t\t\t================";
			cout << "\n\n\t\t\tWhich title's stock do you want to add: ";
			cin.ignore();
			getline(cin,stemp[0]);
			cout << "\n\t\t\tStock: ";
			cin >> itemp;
			file.open("TITLE.txt",ios::in);
			file5.open("STOCK.txt",ios::in);
			while(!file.eof())
			{
				getline(file,title[i]);
				file5 >> stock[i];
				if(stemp[0] == title[i])
				{
					stock[i] = stock[i] + itemp;
					cout << "\n\n\t\t\t" << itemp << " stock added";
					result = 1;
				}
				i++;
			}
			file.close();
			file5.close();
			file5.open("STOCK.txt",ios::out);
			for(i=0;i<5;i++)
			{
				file5 << stock[i] << endl;
			}
			if(result == 0)
			{
				cout << "\n\n\t\t\tNo book as " << stemp[0] << " was found, Press any key to return.";
			}
			file5.close();
			getch();
		}
		sales_report()
		{
			i = 0, result = 0;
			system("cls");
			cout << "\t\t\t==============\n\t\t\t SALES REPORT\n\t\t\t==============";
			cout << "\n\n\t\t\t1. Montly Report";
			cout << "\n\t\t\t2. Quaterly Report";
			cout << "\n\t\t\t3. Yearly Report";
			cout << "\n\n\t\t\tEnter Choice: ";
			cin >> itemp;
			file.open("DATE.txt",ios::in);
			file2.open("SALE.txt",ios::in);
			system("cls");
			cout << "\t\t\t==============\n\t\t\t SALES REPORT\n\t\t\t==============";
			if(itemp == 1)
			{
				cout << "\n\n\t\t\tEnter month (1-12): ";
				cin >> month[0];
				system("cls");
				cout << "\t\t\t==============\n\t\t\t SALES REPORT\n\t\t\t==============";
				while(!file.eof())
				{
					file >> month[1];
					getline(file2,stemp[0]);
					getline(file2,stemp[1]);
					if(month[1] == month[0])
					{
						if(stemp[0] == "")
						{
							break;
						}
						cout << "\n\n\t\t\t" << i+1 << "." << stemp[0];
						cout << "\n\t\t\t" << stemp[1];
						i++,result++;
					}
				}
			}
			if(itemp == 2)
			{
				while(!file.eof())
				{
					file >> month[1];
					getline(file2,stemp[0]);
					getline(file2,stemp[1]);
					if(month[1] == 1 || month[1] == 2 || month[1] == 3)
					{
						if(stemp[0] == "")
						{
							break;
						}
						cout << "\n\n\t\t\t" << i+1 << "." << stemp[0];
						cout << "\n\t\t\t" << stemp[1];
						i++,result++;
					}
				}
			}
			if(itemp == 3)
			{
				while(!file2.eof())
				{
					getline(file2,stemp[0]);
					if(stemp[0] == "")
					{
						break;
					}
					cout << "\n\n\t\t\t" << i+1 << "." << stemp[0];
					getline(file2,stemp[0]);
					cout << "\n\t\t\t" << stemp[0];
					i++,result++;
				}
			}
			cout << "\n\n\t\t\tTotal sales: " << result << ", Press any key to return.";
			if(result == 0)
			{
				cout << "\n\n\t\t\t-No sales found, Press any key to return.";
			}
			file.close();
			file2.close();
			getch();
		}
};

class Admin: public Account
{
	public:
		login()
		{
			cin.ignore();
			r:
			itemp = 0;
			file.open("USERNAME(A).txt",ios::in);
			file2.open("PASSWORD(A).txt",ios::in);
			system("cls");
			cout << "\t\t\t=============\n\t\t\t ADMIN LOGIN\n\t\t\t=============\n\n";
			cout << "\t\t\tUsername: ";
			getline(cin,stemp[0]);
			cout << "\n\t\t\tPassword: ";
			getline(cin,stemp[1]);
			while(!file.eof() && !file2.eof())
			{
				getline(file,un[0]);
				getline(file2,pass[0]);
				if(stemp[0] == un[0] && stemp[1] == pass[0] && stemp[0] != "" && stemp[1] != "")
				{
					login_display();
					choice[2] = 1;
					break;
				}
			}
			file.close();
			file2.close();
			if(choice[2] == 0)
			{
				cout << "\n\n\t\t\t- Login failed.\n\t\t\t- Press R to retry.\n\t\t\t- Press any key to return.";
				itemp = toupper(getch());
				if(itemp == 'R')
				{
					goto r;
				}
			}
		}
		log()
		{
			system("cls");
			cout << "\t\t\t==============\n\t\t\t ADMIN PORTAL\n\t\t\t==============";
			cout << "\n\n\t\t\t1. Add Staff";
			cout << "\n\t\t\t2. Modify Staff";
			cout << "\n\t\t\t3. Delete Staff";
			cout << "\n\t\t\t4. Add Customer";
			cout << "\n\t\t\t5. Modify Customer";
			cout << "\n\t\t\t6. Delete Customer";
			cout << "\n\t\t\t7. Stock Status";
			cout << "\n\t\t\t8. Add Stock";
			cout << "\n\t\t\t9. Sales Report";
			cout << "\n\t\t\t10. Logout";
			cout << "\n\n\n\t\t\tEnter choice: ";
			cin >> choice[3];
		}
		add_staff()
		{
			cin.ignore();
			retry:
			i=0;
			system("cls");
			cout << "\t\t\t=======================\n\t\t\t STAFF ADDITION PORTAL\n\t\t\t=======================";
			cout << "\n\n\t\t\tUsername: ";
			getline(cin,stemp[0]);
			file.open("USERNAME(S).txt",ios::in);
			while(!file.eof())
			{
				getline(file,un[i]);
				if(stemp[0] == un[i])
				{
					cout << "\n\t\t\tUsername already in use, Press any key to retry.";
					getch();
					goto retry;
				}
				i++;
			}
			file.close();
			cout << "\n\t\t\tPassword: ";
			getline(cin,stemp[1]);
			file.open("USERNAME(S).txt",ios::app);
			file2.open("PASSWORD(S).txt",ios::app);
			file << stemp[0] << endl;
			file2 << stemp[1] << endl;
			file.close();
			file2.close();
			system("cls");
			cout << "\t\t\t=======================\n\t\t\t STAFF ADDITION PORTAL\n\t\t\t=======================";
			cout << "\n\n\t\t\t- Staff successfully created, Press any key to return.";
			getch();
		}
		mod_staff()
		{
			i = 0, result = 0;
			system("cls");
			cout << "\t\t\t===============\n\t\t\t STAFF SETTING\n\t\t\t===============";
			cout << "\n\n\t\t\t1. Change Username";
			cout << "\n\t\t\t2. Change Password";
			cout << "\n\n\t\t\tEnter choice: ";
			cin >> itemp;
			if(itemp == 1)
			{
				cin.ignore();
				rr:
				file.open("USERNAME(S).txt",ios::in);
				system("cls");
				cout << "\t\t\t===============\n\t\t\t STAFF SETTING\n\t\t\t===============";
				cout << "\n\n\t\t\tEnter your current username: ";
				getline(cin,stemp[0]);
				cout << "\n\t\t\tEnter new username: ";
				getline(cin,stemp[1]);
				while(!file.eof())
				{
					getline(file,un[i]);
					if(stemp[1] == un[i])
					{
						break;
					}
					if(un[i] == stemp[0])
					{
						un[i] = stemp[1];
						result = 1;
					}
					i++;
				}
				file.close();
				if(result == 0)
				{
					cout << "\n\t\t\t-Invalid username entry.";
					cout << "\n\t\t\t-Press R to retry.";
					cout << "\n\t\t\t-Press any key to return.";
				}
				else
				{
					cout << "\n\t\t\tUsername changed to " << stemp[1] << ", Press any key to return.";
					file.open("USERNAME(S).txt",ios::out);
					for(i=0;i<5;i++)
					{
						if(un[i] == "")
						{
							break;
						}
						file << un[i] << endl;
					}
					file.close();
				}
			}
			else if(itemp == 2)
			{
				cin.ignore();
				rs:
				file.open("USERNAME(S).txt",ios::in);
				file2.open("PASSWORD(S).txt",ios::in);
				system("cls");
				cout << "\t\t\t===============\n\t\t\t STAFF SETTING\n\t\t\t===============";
				cout << "\n\n\t\t\tEnter your current username: ";
				getline(cin,stemp[0]);
				cout << "\n\t\t\tEnter your current password: ";
				getline(cin,stemp[1]);
				cout << "\n\t\t\tEnter new password: ";
				getline(cin,stemp[2]);
				while(!file.eof() && !file2.eof())
				{
					getline(file,un[i]);
					getline(file2,pass[i]);
					if(un[i] == stemp[0] && pass[i] == stemp[1])
					{
						pass[i] = stemp[2];
						result = 1;
					}
					i++;
				}
				file.close();
				file2.close();
				if(result == 0)
				{
					cout << "\n\t\t\t-Incorrect username or password";
					cout << "\n\t\t\t-Press R to retry.";
					cout << "\n\t\t\t-Press any key to return.";
				}
				else
				{
					cout << "\n\t\t\tPassword changed successfully, Press any key to return.";
					file.open("PASSWORD(S).txt",ios::out);
					for(i=0;i<5;i++)
					{
						if(pass[i] == "")
						{
							break;
						}
						file << pass[i] << endl;
					}
					file2.close();
				}
			}
			itemp = toupper(getch());
			if(itemp == 'R')
			{
				goto rs;
			}
		}
		del_staff()
		{
			cin.ignore();
			file.open("USERNAME(S).txt",ios::in);
			file2.open("PASSWORD(S).txt",ios::in);
			system("cls");
			cout << "\t\t\t===============\n\t\t\t STAFF REMOVAL\n\t\t\t===============";
			cout << "\n\n\t\t\tEnter staff username to delete it: ";
			getline(cin,stemp[0]);
			while(!file2.eof())
			{
				getline(file,un[i]);
				getline(file2,pass[i]);
				i++;
			}
			file.close();
			file2.close();
			file.open("USERNAME(S).txt",ios::out);
			file2.open("PASSWORD(S).txt",ios::out);
			for(i=0;i<5;i++)
			{
				if(un[i] == "" && pass[i] == "")
				{
					break;
				}
				if(stemp[0] == un[i])
				{
					itemp++;
				}
				else
				{
					file << un[i] << endl;
					file2 << pass[i] << endl;
				}
			}
			file.close();
			file2.close();
			if(itemp <= 0)
			{
				cout << "\n\t\t\tNo staff found, try again.";
			}
			else
			{
				cout << "\n\t\t\tStaff " << stemp[0] << " has been deleted, press any key to return.";
			}
			getch();
		}
};

class Staff: public Account
{
	public:
		login()
		{
			r:
			file.open("USERNAME(S).txt");
			file2.open("PASSWORD(S).txt");
			system("cls");
			cout << "\t\t\t=============\n\t\t\t STAFF LOGIN\n\t\t\t=============\n\n";
			cout << "\t\t\tUsername: ";
			cin.ignore();
			getline(cin,stemp[0]);
			cout << "\n\t\t\tPassword: ";
			getline(cin,stemp[1]);
			while(!file.eof() && !file2.eof())
			{
				getline(file,un[0]);
				getline(file2,pass[0]);
				if(stemp[0] == un[0] && stemp[1] == pass[0] && stemp[0] != "" && stemp[1] != "")
				{
					login_display();
					choice[2] = 1;
					break;
				}
			}
			file.close();
			file2.close();
			if(choice == 0)
			{
				cout << "\n\n\t\t\t- Login failed.\n\t\t\t- Press R to retry.\n\t\t\t- Press any key to return.";
				itemp = toupper(getch());
				if(itemp == 'R')
				{
					goto r;
				}
			}
		}
		log()
		{
			system("cls");
			cout << "\t\t\t==============\n\t\t\t STAFF PORTAL\n\t\t\t==============";
			cout << "\n\n\t\t\t1. Add Customer";
			cout << "\n\t\t\t2. Modify Customer";
			cout << "\n\t\t\t3. Delete Customer";
			cout << "\n\t\t\t4. Stock Status";
			cout << "\n\t\t\t5. Add Stock";
			cout << "\n\t\t\t6. Sales Report";
			cout << "\n\t\t\t7. Logout";
			cout << "\n\n\n\t\t\tEnter choice: ";
			cin >> choice[3];
		}
};

main()
{
	Bookshop B;
	Admin A;
	Staff S;
	home:
	system("Color 06");
	B.homescreen();
	
	switch(choice[0])
	{
		case 1:
			system("cls");
			cout << "\t\t\t===============\n\t\t\t ACCOUNT LOGIN\n\t\t\t===============\n\n";
			cout << "\t\t\t1. Login as Admin\n\t\t\t2. Login as Staff\n\t\t\t3. Homescreen";
			cout << "\n\n\n\t\t\tEnter choice: ";
			cin >> choice[1];
			switch(choice[1])
			{
				case 1:
					A.login();
					if(choice[2] == 1)
					{
						alogged:
						A.log();
						switch(choice[3])
						{
							case 1:
								A.add_staff();
								goto alogged;
								break;
							case 2:
								A.mod_staff();
								goto alogged;
								break;
							case 3:
								A.del_staff();
								goto alogged;
								break;
							case 4:
								A.add_customer();
								goto alogged;
								break;
							case 5:
								A.mod_customer();
								goto alogged;
								break;
							case 6:
								A.del_customer();
								goto alogged;
								break;
							case 7:
								A.stock_check();
								goto alogged;
								break;
							case 8:
								A.add_stock();
								goto alogged;
								break;
							case 9:
								A.sales_report();
								goto alogged;
								break;
							case 10:
								choice[2] = 0;
								goto home;
								break;
							default:
								cout << "\n\t\t\tInvalid choice, press any key to try again.";
								getch();
								goto alogged;
								break;
						}
					}
					break;
				case 2:
					S.login();
					if(choice[2] == 1)
					{
						slogged:
						S.log();
						switch(choice[3])
						{
							case 1:
								S.add_customer();
								goto slogged;
								break;
							case 2:
								S.mod_customer();
								goto slogged;
								break;
							case 3:
								S.del_customer();
								goto slogged;
								break;
							case 4:
								S.stock_check();
								goto slogged;
								break;
							case 5:
								S.add_stock();
								goto slogged;
								break;
							case 6:
								S.sales_report();
								goto slogged;
								break;
							case 7:
								choice[2] = 0;
								goto home;
								break;
							default:
								cout << "\n\t\t\tInvalid choice, press any key to try again.";
								getch();
								goto slogged;
								break;
						}
					}
					break;
				case 3:
					goto home;
					break;
				default:
					cout << "\n\t\t\tInvalid choice, press any key to try again.";
					getch();
					break;
			}
			break;
		case 2:
			B.books();
			break;
		case 3:
			B.book_search();
			break;
		case 4:
			B.buy();
			break;
		case 5:
			exit(0);
			break;
		default:
			cout << "\n\t\t\tInvalid choice, press any key to try again.";
			getch();
			break;
	}
	goto home;
}

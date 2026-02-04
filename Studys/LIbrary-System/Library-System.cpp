#include <iostream>
#include <vector>
using namespace std;

class Client
{
protected:
	string name;
	int cpf;
public:
	Client(string n, int c)
	{
		this->name = n;
		this->cpf = c;
	}

	void print()
	{
		cout << this->name << this->cpf << endl;
	}

	string get_name()
	{
		return this->name;
	}

	int get_cpf()
	{
		return this->cpf;
	}
};

class Book
{
protected:
	string name;
	string author;
public:

	Book(string n, int a)
	{
		this->name = n;
		this->author = a;
	}
	void print()
	{
		cout << this->name << this->author << endl;
	}

	string get_name()
	{
		return this->name;
	}

	string get_author()
	{
		return this-> author;
	}
};

class Loan
{
protected:
	Client* client;
	Book* book;
	
	int year;
};

class Library
{
protected:
	vector<Client> clients;
	vector<Book> books;
	vector<Loan> loans;
public:
	void register_client(Client _client)
	{
		this->clients.push_back(_client);
	}
	void register_book(Book _book)
	{
		this->books.push_back(_book);
	}

	void print_client()
	{
		for (Client client : clients)
		{
			client.print();
		}
	}

	void print_book()
	{
		for (Book book : books)
		{
			book.print();
		}
	}

	void delet_client(Client& _client)
	{
		for (int i = 0; i < clients.size(); i++)
		{
			if (_client.get_name() == this->clients[i].get_name() &&
			_client.get_cpf() == this->clients[i].get_cpf())
			{
				this->clients.erase(this->clients.begin() + i);
			}
		}
	}

	void delet_book(Book& _book)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (_book.get_name() == this->books[i].get_name() &&
			_book.get_author() == this->books[i].get_author())
			{
				this->books.erase(this->books.begin() + i);
			}
		}
	}

	void replace_client(Client client_previos, Client client_new)
	{
		for (int i = 0; i < clients.size(); i++)
		{
			if (client_previos.get_name() == this->clients[i].get_name() &&
			client_previos.get_cpf() == this->clients[i].get_cpf())
			{
				this->clients[i] = client_new;
			}
		}
	}

	void replace_book(Book book_previos, Book book_new)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (book_previos.get_name() == this->books[i].get_name() &&
			book_previos.get_author() == this->books[i].get_author())
			{
				this->books[i] = book_new;
			}
		}
	}
};

 int main (void)
 {
	return 0;
 }
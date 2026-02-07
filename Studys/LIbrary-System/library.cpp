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
		cout << this->name << " " << this->cpf << endl;
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

	Book(string n, string a)
	{
		this->name = n;
		this->author = a;
	}
	void print()
	{
		cout << this->name << " " << this->author << endl;
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

public:
	Loan(Client _client, Book _book)
	{
		this->client = &_client;
		this->book = &_book;
	}

	void print()
	{
		cout << client->get_name() << " " << book->get_name() << " " << this->year  << endl;
	}
	
	Client get_client()
	{
		return *client;
	}

	Book get_book()
	{
		return *book;
	}

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

	void register_loan(int _cpf, Book _book)
	{
		int cli_index = -1;
		int book_index = -1;
		for (int i = 0; i < this->clients.size(); i++)
		{
			if (_cpf == this->clients[i].get_cpf())
			{
				cli_index = i;
				break;
			}
		}

		if (cli_index == -1) {	return;	}

		for (int i = 0; i < this->books.size(); i++)
		{
			if (_book.get_name() == this->books[i].get_name() &&
			_book.get_author() == this->books[i].get_author())
			{
				book_index = -1;
				break;
			}
		}

		if (book_index == -1) { return;}

		Loan loan(this->clients[cli_index], this->books[book_index]);
		this->loans.push_back(loan);
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

	void print_loan()
	{
		for (Loan loan : loans)
		{
			loan.print();
		}
	}

	void delet_client(int _cpf)
	{
		for (int i = 0; i < this->clients.size(); i++)
		{
			if (_cpf == this->clients[i].get_cpf())
			{
				this->clients.erase(this->clients.begin() + i);
			}
		}
	}

	void delet_book(Book& _book)
	{
		for (int i = 0; i < this->books.size(); i++)
		{
			if (_book.get_name() == this->books[i].get_name() &&
			_book.get_author() == this->books[i].get_author())
			{
				this->books.erase(this->books.begin() + i);
			}
		}
	}

	void delet_loan(Loan& _loan)
	{
		for (int i = 0; i < loans.size(); i++)
		{
			if (_loan.get_client().get_cpf() == this->loans[i].get_client().get_cpf() &&
			_loan.get_book().get_name() == this->loans[i].get_book().get_name() &&
			_loan.get_book().get_author() == this->loans[i].get_book().get_author())
			{
				this->loans.erase(this->loans.begin() + i);
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

	void replace_loan(Loan loan_previos, Loan loan_new)
	{
		for (int i = 0; i < loans.size(); i++)
		{
			if (loan_previos.get_client().get_cpf() == this->loans[i].get_client().get_cpf() &&
			loan_previos.get_book().get_name() == this->loans[i].get_book().get_name() &&
			loan_previos.get_book().get_author() == this->loans[i].get_book().get_author())
			{
				this->loans[i] = loan_new;
			}
		}
	}
};

class System
{
protected:
	Library library;
public:
	void run()
	{
		int opcao = 0;
		cout << "[1] Cadastrar aluno" << endl;
		cout << "[2] Cadastrar livro" << endl;
		cout << "[3] Emprestar livro para aluno" << endl << endl;

		cout << "[4] Deletar aluno " << endl;
		cout << "[5] Deletar livro " << endl;
		cout << "[6] Fazer devolução de livro" << endl << endl;
		
		cout << "[7] Visualizar alunos " << endl << endl;
		cout << "[8] Visualizar livros" << endl;
		cout << "[9] Visualizar empréstimos" << endl << endl;

		cout << "[10] Alterar aluno " << endl;
		cout << "[11] Alterar livro" << endl;
		
		
		cout << "[12] Parar execução do programa" << endl << endl;
		
		
		
		
		
		cin >> opcao;
		while(opcao != 12)
		{
			switch(opcao)
			{
				case (1):
					this->library.register_client(this->create_client());
					break;
				case (2):
					this->library.register_book(this->create_book());
					break;
				case (3):
					this->library.register_loan(this->get_cpf(), this->create_book());
					break;
				case (4):
					break;
			}
			


			cin >> opcao;
		}
	}

	int get_cpf()
	{
		cout << "Digite o cpf do cliente" << endl;
		int cpf;
		cin >> cpf;
		return cpf;
	}
	Client create_client()
	{
		string name;
		cout << "Digite o nome do cliente" << endl;
		cin >> name;

		int cpf = this->get_cpf();


		return Client(name,cpf);
	}

	Book create_book()
	{
		string name;
		string author;
		cout << "Digite o nome do livro" << endl;
		cin >> name;
		cout << "Digite o author do livro" << endl;
		cin >> author;

		Book book(name, author);
		return book;
	}
};

 int main (void)
 {
	System system;
	system.run();
	return 0;
 }
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
		if (clients.empty())
		{
			cout << "Não a clientes" << endl;
		}
		for (Client client : clients)
		{
			client.print();
		}
	}

	void print_book()
	{
		if (this->books.empty())
		{
			cout << "Não a livros" << endl;
		} else {
			for (Book book : books)
			{
				book.print();
			}
		}
	}

	void print_loan()
	{
		if (this->loans.empty())
		{
			cout << "Não a emprésitmos" << endl;
		} else {
			for (Loan loan : loans)
			{
				loan.print();
			}
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

	void delet_book(Book _book)
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

	void delet_loan(int cpf, Book book)
	{
		for (int i = 0; i < loans.size(); i++)
		{
			if (cpf == this->loans[i].get_client().get_cpf() &&
			book.get_name() == this->loans[i].get_book().get_name() &&
			book.get_author() == this->loans[i].get_book().get_author())
			{
				this->loans.erase(this->loans.begin() + i);
			}
		}
	}

	void replace_client(int cpf, Client client_new)
	{
		for (int i = 0; i < clients.size(); i++)
		{
			if (cpf == this->clients[i].get_cpf())
			{
				this->clients[i] = client_new;
				cout << "Cliente encontrado com sucesso" << endl; 
				return;
			}
		}
		cout << "Cliente não encontrado" << endl; 
	}

	void replace_book(Book book_previos, Book book_new)
	{
		
		for (int i = 0; i < books.size(); i++)
		{
			if (book_previos.get_name() == this->books[i].get_name() &&
			book_previos.get_author() == this->books[i].get_author())
			{
				this->books[i] = book_new;
				cout << "Livro encontrado com sucesso" << endl; 
				return;
			}
		}
		cout << "Livro não encontrado" << endl; 
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

		while(opcao != 12)
		{
			opcao = options();
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
					this->library.delet_client(this->get_cpf());
					break;
				case (5):
					this->library.delet_book(this->create_book());
					break;
				case (6):
					cout << "Digite o cpf do cliente" << endl;
					this->library.delet_loan(this->get_cpf(), this->create_book());
					break;
				case (7):
					this->library.print_client();
					break;
				case (8):
					this->library.print_book();
					break;
				case (9):
					this->library.print_loan();
					break;
				case (10):
					this->replace_client();
				case (11):
					this->replace_book();
			}
		}
	}

	void replace_client()
	{
		cout << "Digite o cpf do cliente que deseja modificar" << endl;
		int cpf = this->get_cpf();

		cout << "Digite as novas informaçõs do cliente:" << endl;
		Client client = this->create_client();

		this->library.replace_client(cpf, client);
	}

	void replace_book()
	{
		cout << "Digite as informações solicitadas a seguir do livro que deseja modificar" << endl;
		Book book_previos = this->create_book();

		cout << "Digite as novas informaçõs do livro:" << endl;
		Book book_new = this->create_book();

		this->library.replace_book(book_previos, book_new);
	}



	int options()
	{
		cout << "[1] Cadastrar aluno" << endl;
		cout << "[2] Cadastrar livro" << endl;
		cout << "[3] Emprestar livro para aluno" << endl << endl;

		cout << "[4] Deletar aluno " << endl;
		cout << "[5] Deletar livro " << endl;
		cout << "[6] Fazer devolução de livro" << endl << endl;
		
		cout << "[7] Visualizar alunos " << endl;
		cout << "[8] Visualizar livros" << endl;
		cout << "[9] Visualizar empréstimos" << endl << endl;

		cout << "[10] Alterar aluno " << endl;
		cout << "[11] Alterar livro" << endl;

		cout << "[12] Parar execução do programa" << endl << endl;	
		
		int opcao;
		cin >> opcao;
		return opcao;
	}

	int get_cpf()
	{
		int cpf;
		cin >> cpf;
		return cpf;
	}
	Client create_client()
	{
		string name;
		cout << "Digite o nome do cliente" << endl;
		cin >> name;
		cout << "Digite o cpf do cliente" << endl;
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
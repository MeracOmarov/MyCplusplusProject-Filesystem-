#include<iostream>
#include<vector>
#include<cassert>
#include<fstream>
#include<list>
#include<map>
#include<stdio.h>
#include <sys/stat.h>
#include <string>
#include <filesystem>
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <filesystem>
#include<direct.h>
#include<cstdio>
using namespace std;
class File
{
protected:
	void set_file_name(string filename)
	{
		_file.open(filename);
		_file.close();
	}
	void renamefile(string filename, string newfilename)
	{
		int a = rename(filename.c_str(), newfilename.c_str());
		if (a == -1) throw exception("ERROR:  file is not found!!");

	}
	void remove_file(string filename)
	{
		remove(filename.c_str());
	}
	void read_file(string filename)
	{
		this->_filee.open(filename);
		if (this->_filee)
		{
			string* data = new string;
			getline(this->_filee, *data, '\0');
			cout << *data;
		}
		else
		{
			throw exception("ERROR:  file is not found!!");
		}
	}
	void write_file(string file, string dat)
	{
		string* data = new string (dat);
		this->_file.open(file, ios::app);
		if (this->_filee)
		{
			this->_file << " " << *data;
			this->_file.close();
		}
		else
		{
			throw exception("ERROR:  file is not found!!");
		}
	}
 public:
	 ofstream _file;
	 ifstream _filee;
	 string _filename="C:/Users/Meraj/source/repos/homework/homework/";
	 string* text = new string;
	 File() {};
	 File(string filename) : _file(filename) { _file.close(); _filename = filename; };
    
	 virtual ~File()=0{};
};
class Folder
{
protected:
	void create_folder(string foldername)
	{
		string a = "mkdir " + foldername;
		_foldername = foldername;
		system(a.c_str());
	}
	void re_name_folder(string name1)
	{
		string newname;
		cout << "include new folder name ";
		cin >> newname;
		int a = rename(name1.c_str(), newname.c_str());
		if (a == -1) throw exception("ERROR:  Folder is not found!!");
	}
	void delete_folder(string name1)
	{
		string a = "rmdir " + name1;
		system(a.c_str());
	}
	void create_sub_folder(string second)
	{
		string first;
		cout << "include in Which folder subfolder is going to create" << endl;
		cin.ignore(1);
		getline(cin, first);
		string path1 = "C://Users//Meraj//source//repos//homework//homework//" + first + "//" + second;
		if (_mkdir(path1.c_str()) == -1)
		{
			throw exception("subfolder could not be created");
		}
		else
		{
			cout << " folder is created successfully";
		}
	}
	void move_folder(string folder)
	{
		string first;
		cout << "include in Which folder subfolder is going to locate" << endl;
		cin.ignore(1);
		getline(cin, first);
		string path1 = "C://Users//Meraj//source//repos//homework//homework//" + first + "//" + folder;
	}
	void show_allfil(string filename)
	{
		if (filename == "homework")
		{
			string a1 = "C:\\Users\\Meraj\\source\\repos\\homework\\";
			a1.append("homework");
			cout << a1;
			string aa = "dir / a - d ";
			aa.append(a1);
			system(aa.c_str());
		}
		else
		{
			string a1 = "C:\\Users\\Meraj\\source\\repos\\homework\\";
			a1.append("homework\\");
			a1.append(filename);
			cout << a1;
			string aa = "dir / a - d ";
			aa.append(a1);
			system(aa.c_str());
		}

	}
public:
	string _foldername;
	Folder() {};
	Folder(string foldername) {
		string a = "mkdir " + foldername;
		_foldername = foldername;
		system(a.c_str());
	};
	virtual ~Folder() = 0 {}
};
class Function : public Folder, public File
{
public:
	void make_folder(string name1)
	{
		Folder::create_folder(name1);
		cout << "New folder  is created  successfully" << endl;
	}
	void make_file(string name1)
	{
		File::set_file_name(name1);
		cout << "New file  is created  successfully" << endl;
	}
	void rename_file(string old)
	{
		string newname;
		cout << "include new file name ";
		cin >> newname;
		File::renamefile(old, newname);
		cout << "New name  is implemented successfully" << endl;
	}
	void rename_folder(string name1)
	{
		Folder::re_name_folder(name1);
		cout << "New name is implemented successfully" << endl;
	}
	void remove_file(string name1)
	{
		File::remove_file(name1);
		cout << "File is removed successfully" << endl;
	}
	void remove_folder(string name1)
	{
		Folder::delete_folder(name1);
		cout << "Folder is removed successfully" << endl;
	}
	void read_file(string name1)
	{
		File::read_file(name1);
	}
	void write_mode_app(string file)
	{
		string text;
		cout << "Include text: " << endl;
		cin.ignore(1);
		getline(cin, text);
		File::write_file(file,text);
	}
	void print_all(string name1)
	{
		Folder::show_allfil(name1);
	}
	void move_file(string name1)
	{
		string __scr;
		string _dst;
		string __dst;
		__scr = File::_filename + name1;
		cout << "include destination: (name of  subfolder)";
		cin.ignore(1);
		getline(cin, _dst);
		__dst = File::_filename + _dst + "/" + name1;
		File::set_file_name(__dst);
		cout << __scr << endl;
		cout << __dst << endl;
		ifstream scr(__scr, std::ios::binary);
		ofstream dst(__dst, std::ios::binary);
		dst << scr.rdbuf();
		dst.close();
		scr.close();
		File::remove_file(__scr);
	}
	void open_file()
	{
		string topicName;
		cout << "\t\tWhich Topic You Want to edit: ";
		getline(cin, topicName);
		topicName = "notepad \"" + topicName + "\"";
		system(topicName.c_str());
	}
	void subfolder(string name)
	{
		Folder::create_sub_folder(name);
	}
	void helping()
	{
		cout << "mkdir --/make folder" << endl;
		cout << "mkfil --/make file" << endl;
		cout << "rnfil --/rename file" << endl;
		cout << "rnfol --/rename folder" << endl;
		cout << "dfil --/delete file" << endl;
		cout << "dfol --/delete folder" << endl;
		cout << "rfil --/read file" << endl;
		cout << "wfil --/write in file (app mode)" << endl;
		cout << "pall --/print all" << endl;
		cout << "ofil --/open file" << endl;
	}
};
class Main : Function
{
public:
	void body(string name1, string command1)
	{
		Function Fun;
		if (command1 == "mkdir") // make folder
		{
			Fun.make_folder(name1);
		}
		else if (command1 == "mkfil") // make file
		{
			Fun.make_file(name1);
		}
		else if (command1 == "rnfil") //rename file
		{
			Fun.rename_file(name1);
		}
		else if (command1 == "rnfol") // rename folder
		{
			Fun.rename_folder(name1);
		}
		else if (command1 == "dfil") // delete file
		{
			Fun.remove_file(name1);
		}
		else if (command1 == "dfol") // delete folder
		{
			Fun.remove_folder(name1);
		}
		else if (command1 == "rfil")   // read file
		{
			Fun.read_file(name1);
		}
		else if (command1 == "wfil")  //write in file (app mode)
		{
			Fun.write_mode_app(name1);
		}
		else if (command1 == "pall") // print all
		{
			Fun.print_all(name1);
		}
		else if (command1 == "mfil") // mfill
		{
			Fun.move_file(name1);
		}
		else if (command1 == "ofil") //open file
		{
			Fun.open_file();
		}
		else if (command1 == "help") // help -- you have to write like that
		{
			Fun.helping();
		}
		else if (command1 == "csfol") // create subfolder
		{
			Fun.subfolder(name1);
		}
		else
		{
			cout << "invalid command"<<endl;
		}
		//else if (command1 == "mfol") // move folder
		//{
		//	break;
		//}
		
	}
};
int main()
{
	string command1;
	string name1;
	Main Fun;
	while (true)
	{
		try
		{
			cout << "System: ";
			cin >> command1 >> name1;
			Fun.body(name1, command1);
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
	}

	


	
	
	


}
	

	

	
	
	

			
				
				
		

	
	
	
	
	

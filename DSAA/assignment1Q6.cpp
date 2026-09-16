#include <iostream>
using namespace std;

class song
{
private:
    string title;
    string genre;
    int duration;
    bool explicitt;

public:
    song(string title,string genre,int duration,bool ex)
    {
        this->title=title;

        if(genre!="pop" && genre!="rock" && genre!="jazz" &&
           genre!="classical" && genre!="electronic")
        {
            cout<<"Invalid Genre!"<<endl;
            this->genre="";
        }
        else
        {
            this->genre=genre;
        }

        this->duration=duration;
        this->explicitt=ex;
    }

    song(){}

    string gettitle(){return title;}
    string getgenre(){return genre;}
    int getduration(){return duration;}
    bool getexplicitt(){return explicitt;}

    void setexplicitt(bool ex)
    {
        explicitt=ex;
    }
};

class node
{
public:
    node* next;
    song* songinfo;

    node(song* songinfo,node* node)
    {
        this->songinfo=songinfo;
        this->next=node;
    }

    node(song* s)
    {
        this->songinfo=s;
        this->next=nullptr;
    }

    node()
    {
        songinfo=nullptr;
        next=nullptr;
    }
};

class playlist
{
private:
    node* head;

    bool validposition(node* previous,node* subject,node* nextnode)
    {
        if(previous!=nullptr)
        {
            if(previous->songinfo->getgenre()==subject->songinfo->getgenre())
                return false;
        }

        if(nextnode!=nullptr)
        {
            if(nextnode->songinfo->getgenre()==subject->songinfo->getgenre())
                return false;
        }

        if(previous!=nullptr && nextnode!=nullptr)
        {
            if(previous->songinfo->getduration()+
               subject->songinfo->getduration()+
               nextnode->songinfo->getduration()>600)
            {
                return false;
            }
        }

        if(subject!=nullptr && nextnode!=nullptr && nextnode->next!=nullptr)
        {
            if(subject->songinfo->getduration()+
               nextnode->songinfo->getduration()+
               nextnode->next->songinfo->getduration()>600)
            {
                return false;
            }
        }

        return true;
    }

public:

    playlist(node* node)
    {
        this->head=node;
    }

    playlist()
    {
        head=nullptr;
    }

    void insert(int position,node* subject)
    {
        if(subject==nullptr)
            return;

        if(head==nullptr)
        {
            head=subject;
            subject->next=nullptr;
            return;
        }

        if(position<=1)
        {
            if(validposition(nullptr,subject,head))
            {
                subject->next=head;
                head=subject;
                return;
            }

            position=2;
        }

        node* temp=head;
        int positionfinder=1;

        while(positionfinder<position-1 && temp->next!=nullptr)
        {
            temp=temp->next;
            positionfinder++;
        }

        while(temp!=nullptr)
        {
            node* temp2=temp->next;

            if(validposition(temp,subject,temp2))
            {
                temp->next=subject;
                subject->next=temp2;
                return;
            }

            temp=temp->next;
        }

        node* last=head;

        while(last->next!=nullptr)
        {
            last=last->next;
        }

        if(validposition(last,subject,nullptr))
        {
            last->next=subject;
            subject->next=nullptr;
        }
    }

    void deletee(int position)
    {
        if(head==nullptr || position<1)
            return;

        node* temp=head;

        if(position==1)
        {
            if(temp->songinfo->getexplicitt()==true)
                return;

            head=head->next;
            delete temp;
            return;
        }

        int positionfinder=1;

        while(positionfinder<position-1 && temp->next!=nullptr)
        {
            temp=temp->next;
            positionfinder++;
        }

        if(temp->next==nullptr)
            return;

        node* temp2=temp->next;

        if(temp2->songinfo->getexplicitt()==true)
            return;

        temp->next=temp2->next;

        delete temp2;
    }

    node* search(string title)
    {
        node* temp=head;

        while(temp!=nullptr)
        {
            if(temp->songinfo->gettitle()==title)
                return temp;

            temp=temp->next;
        }

        return nullptr;
    }

    void display()
    {
        node* temp=head;

        while(temp!=nullptr)
        {
            cout<<temp->songinfo->gettitle()<<" | "
                <<temp->songinfo->getgenre()<<" | "
                <<temp->songinfo->getduration()<<" | "
                <<temp->songinfo->getexplicitt()<<endl;

            temp=temp->next;
        }
    }
};

int main()
{
    playlist p;

    song* s1=new song("Believer","rock",204,false);
    song* s2=new song("Shape of You","pop",233,false);
    song* s3=new song("Blinding Lights","electronic",200,true);
    song* s4=new song("Perfect","pop",263,false);
    song* s5=new song("Fur Elise","classical",180,false);
    song* s6=new song("Take Five","jazz",300,false);

    node* n1=new node(s1);
    node* n2=new node(s2);
    node* n3=new node(s3);
    node* n4=new node(s4);
    node* n5=new node(s5);
    node* n6=new node(s6);

    p.insert(1,n1);
    p.insert(2,n2);
    p.insert(3,n3);
    p.insert(4,n4);
    p.insert(5,n5);
    p.insert(6,n6);

    cout<<"Playlist:"<<endl;
    p.display();

    cout<<endl;

    node* result=p.search("Blinding Lights");

    if(result!=nullptr)
        cout<<"Song found"<<endl;
    else
        cout<<"Song not found"<<endl;

    p.deletee(3);

    return 0;
}
#include<iostream>
using namespace std;
class node
{
   private:
   string title;
   node*left;
   node*right;
   public:
   node(string title="null")
   {
     this->title=title;
     this->left=nullptr;
     this->right=nullptr;
   }
   void display()
   {
     cout << this->title;
   }
friend class BINARY_TREE;

};
class BINARY_TREE
{   private:
    node*root;
    public:
    BINARY_TREE()
    {
     root =nullptr;
    } 
    BINARY_TREE(string title)
    {
       root=new node(title);
    }
    void display()
    {
         if(root==nullptr)
         {
             cout<<"Empty Book Record "<<endl;
             return;
         }
         cout<<"Book record for->"<<root->title<<endl;
         preorder(root);
     }
     void preorder(node*root);
     void addchapter(string chapter_name);
     void addsection(string chapter_name,string section_name);
     void addsubsection(string chapter_name,string section_name,string sub_section_name);
     node*search(node*start,string title);
     node*searchlast(node*start);
};
node*BINARY_TREE::search(node*start,string title)
{
     node*last;
     last=start;
     if (last==nullptr)
     {
          return nullptr;
     }
     else
     {
          while(last!=nullptr)
          {
               if(last->title==title)
               {
                    return last;
               }
               last=last->right;
          }

          return nullptr;
     }

}
 node*BINARY_TREE::searchlast(node*start)
 {
     node*current;
     current=start;
     while(current->right!=nullptr)
     {
          current=current->right;
     }
     return current;
 }
 void BINARY_TREE::preorder(node*root)
 {   if(root!=nullptr)
     {
         cout<<root->title<<endl;
         preorder(root->left);
         preorder(root->right);
     }
 }
 void BINARY_TREE::addchapter(string chapter_name)
 {
        if(root==nullptr)
        {
          cout<<"Empty book record ..... can't add chapter "<<endl;
          return;
        }
        else
        {
               node*chapter,*lastchapter;
               lastchapter=nullptr;
               chapter=root->left;
               if(chapter==nullptr)
               {
                    root->left=new node(chapter_name);
                    cout<<chapter_name<<" added successfully as the first chapter in the book "<<root->title<<endl;
               }
               else
               {
                    chapter=search(chapter,chapter_name);
                    if(chapter==nullptr)
                    {
                         lastchapter=searchlast(root->left);
                         lastchapter->right=new node(chapter_name);
                         cout<<chapter_name<<"added successfully as the last chapter in the book"<<root->title<<endl;
                    }
                    else
                    {
                        cout<<"Error : duplicate chapter present in book "<<endl;
                    }
               }

          }
 }
 void BINARY_TREE::addsection(string chapter_name,string section_name)
 {
       if(root==nullptr)
        {
          cout<<"Empty book record ..... can't add section "<<endl;
          return;
        }
        else
        {
             node*chapter,*section,*lastsection;
             chapter=root->left;
             if(chapter==nullptr)
             {
               cout<<"Can't add section cause no chapter is present in book"<<endl;
               return;
             }
             else
             {
                  chapter=search(chapter,chapter_name);
                  if(chapter==nullptr)
                  {
                    cout<<"Cant add section cause couldn't find the entered chapter name"<<endl;
                    return;
                    
                  }
                  else
                  {
                        section = chapter->left;
                        if(section==nullptr)
                        {
                         chapter->left=new node(section_name);
                         cout<<section_name<<"added successfully as the first section in the chapter"<<chapter_name<<endl;

                        }
                        else
                        {
                             section = search(section,section_name);
                             if(section==nullptr)
                             {
                               lastsection =searchlast(chapter->left);
                               lastsection->right=new node(section_name);
                               cout<<section_name<<"added successfully as the last section in the chapter"<<chapter_name<<endl;
                             }
                             else
                             {
                              cout<<"cant add section cause duplicate section found in the book "<<endl;

                             }
                        }

                  }
                      
             }
              
        }
 }
 void BINARY_TREE::addsubsection(string chapter_name,string section_name,string sub_section_name)
 {
        if(root==nullptr)
        {
          cout<<"Empty book record ..... can't add subsection "<<endl;
          return;
        }
        else
        {
              node*chapter,*section,*subsection,*lastsubsection;
              chapter=root->left;
             if(chapter==nullptr)
             {
               cout<<"Can't add subsection cause no chapter is present in book"<<endl;
               return;
             }
             else
             {
                  chapter=search(chapter,chapter_name);
                  if(chapter==nullptr)
                  {
                    cout<<"Cant add subsection cause couldn't find the entered chapter name"<<endl;
                    return;
                  }
                  else
                  {
                    section=chapter->left;
                    if(section==nullptr)
                    {
                         cout<<"Cant add subsection cause there are no sections present in the book"<<endl;
                         return;                    
                    }
                    else
                    {
                         section=search(section,section_name);
                         if(section==nullptr)
                         {
                              cout<<"Cant add subsection cause couldn't find the entered section name"<<endl;
                              return;
                         }
                         else
                         {
                              subsection=section->left;
                              if(subsection==nullptr)
                              {
                                   section->left=new node(sub_section_name);
                                   cout<<sub_section_name<<"added succesfully as the first subsection in the section "<<section_name<<endl;

                              }
                              else
                              {
                                   subsection=search(subsection,sub_section_name);
                                   if(subsection==nullptr)
                                   {
                                        lastsubsection=searchlast(section->left);
                                        lastsubsection->right=new node(sub_section_name);
                                        cout<<sub_section_name<<"added succesfully as the last subsection in the section "<<section_name<<endl;
                                   }
                                   else
                                   {
                                        cout<<"Cant add subsection cause duplicate subsection found in the book"<<endl;
                                   }
                              }
                         }
                    }
                  }
             }
        }
 }
 int main()
 {
     string chapter_name,section_name,sub_section_name;
     int choice;
     
     BINARY_TREE book("Data structure and algorithms");
     do
     {
          cout<<"*****MENU******"<<endl;
          cout<<"1.Add Chapter"<<endl;
          cout<<"2.Add section"<<endl;
          cout<<"3.Add subsection"<<endl;
          cout<<"4.Display"<<endl;
          cout<<"5.Exit"<<endl;
          cout<<"Enter your choice:"<<endl;
          cin>>choice;
          switch (choice)
          {
          case 1:
               cout<<"Enter chapter name:"<<endl;
               cin>>chapter_name;
               book.addchapter(chapter_name); 
               break;
          case 2:
               cout<<"Enter chapter name:"<<endl;
               cin>>chapter_name;
               cout<<"Enter section name:"<<endl;
               cin>>section_name;
               book.addsection(chapter_name,section_name); 
               break;
          case 3:
               cout<<"Enter chapter name:"<<endl;
               cin>>chapter_name;
               cout<<"Enter section name:"<<endl;
               cin>>section_name;
               cout<<"Enter subsection name:"<<endl;
               cin>>sub_section_name;
               book.addsubsection(chapter_name,section_name,sub_section_name); 
               break;
          case 4:
               cout<<"******Displaying Book Record*********"<<endl;
               book.display(); 
               break;
          case 5:
               cout<<"CODE EXITED SUCCESFULLY";
               break;
          default:
               cout<<"Please enter valid choice from 1 to 5"<<endl;
               break;
          }
          
     } while (choice!=5);
     return 0;
}

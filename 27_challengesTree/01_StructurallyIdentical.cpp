using namespace std;
int x=0;

class node{

    public:
    node*right=NULL;
    node*left=NULL;
    int data;

    node(int d){
        data=d;
    }

};

node*insert(node*&root){

if(x==0){
    int k;
    cin>>k;
    x++;
    root=new node(k);
    //cout<<k<<endl;
    root->left=insert(root->left);
    root->right=insert(root->right);
    return root;
}

   string s="abc";
   cin>>s;
    if(s!="abc"){

       if(s=="true"){
       int d;
       cin>>d;
       //cout<<d<<" "<<s<<endl;
       node*nn=new node(d);
       nn->left=insert(nn->left);
       nn->right=insert(nn->right);
       return nn;

      }

      else{
         return root;
      }

  }

    return root;

}

void print(node*root){

    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);

    return;
}


/*=================================
=            Algorithm            =
=================================

    1. If both trees are empty then return 1.
    2. Else If both trees are non-empty:
        Check left subtrees recursively i.e., call isSameStructure(tree1->left_subtree, tree2->left_subtree)
        Check right subtrees recursively i.e., call isSameStructure(tree1->right_subtree, tree2->right_subtree)
    3. If the value returned in above two steps are true then return 1.
        Else return 0 (one is empty and other is not).

/*=====  End of Algorithm  ======*/


bool Identical(node* r1, node* r2){

    if(r1 == nullptr and r2 == nullptr)
        return true;

    if(r1 != nullptr and r2 != nullptr){
        return (Identical(r1->left, r2->left) and Identical(r1->right, r2->right));
    }

    // if one root has child and other dont.
    return false;
}

int main() {
   node*root1=NULL;
   node*root2=NULL;
   x=0;
    insert(root1);
 x=0;
    insert(root2);

    if(Identical(root1,root2)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }

    //print(root2);

}

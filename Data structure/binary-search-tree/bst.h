#include<iostream> 
#define NONE -0x3f3f3f3f


template<typename T>
class BST;
template<typename T>
class Node;

template<typename T> 
class Node{
    /************ Data Area ***********/
    T __key;
    Node<T> *left,*right,*father;
    friend class BST<T>; 
    /************ Methods *************/
    public:
    int flag; //用来判断当前结点是父亲孩子的左结点还是右结点

   
    Node(int key = NONE){
        left = right =father = NULL;
        flag = 0;
        __key = key;
    }

    bool equals (Node<T> &obj) {
        return this->__key == obj.__key;
    }

    bool bigger(Node<T> &obj) {
        return  this->__key > obj.__key;
    }

    Node<T>* get_left(){
        return left;
    }

    Node<T> *get_right(){
        return right;
    }

    Node<T>* get_father(){
        return father;
    }
    
    void set_left(Node<T>* _left){
        left = _left;
    }

    void set_right(Node<T> * _right){
        right = _right;
    }

    void set_father(Node<T>* _father){
        father = _father;
    }
};


template<typename T>
class BST{

    /************ Data Area ***********/
    typedef Node<T> node;
    node* root;

    /************ Methods *************/
    public:
    BST(){
        root = NULL;
    }
    
    node* search(node element){
        node* x = root;
        while(x != NULL){
            if(x->equals(element)){
                return x;
            }else if(x->bigger(element)){
                x = x->get_left(); 
            }else{
                x = x->get_right();
            }
        }
        return x;
    }

    //以r结点的后继
    node* find_min(node* r){
        if(r==NULL){
            return NULL;
        }
        while(r->left!=NULL){
            r = r->left;
        }
        return r;
    }

    void Insert(T element){
        node *ele = new node(element);
        //先找到要插入的位置
        node* x = root;
        node* y = x;  //y是记录x的父亲
        int flag = 0;

        while(x!=NULL){
            y = x;
            if(x->bigger(*ele)){
                x = x->get_left();
                flag = 0;
            }else{
                x = x->get_right();
                flag = 1;
            }
        }
		if (y == NULL) {
			root = ele;
			return;
		}
        ele->flag = flag;
        ele->set_father(y);

        //如果x是y的右孩子
        if(flag){
            y->set_right(ele);
        }else{
            y->set_left(ele);
        }
    }
    
    bool Delete(T element){
        node* x = search(element);
		//如果x不在二叉搜索树中，则直接返回
        if(x == NULL){
            return false;
        }
		//需要删除的元素
        node* ele = new node(element);
        int flag = x->flag;
		//后继的指针
		node* successor = find_min(x->right);
		bool rm_root = false;

        //结点没有孩子
        if(x->get_left()==NULL&&x->get_right()==NULL){
			//如果当前节点为根结点，则直接删除
			if (x == root) {
				root = NULL;
				delete x;
				return true;
			}
			//否则需要更新一下father的指针
            if(flag){
				if(x->father!=NULL)
					x->father->right = NULL;
            }else{
				if(x->father!=NULL)
					x->father->left = NULL;
            }
        }

        //结点有两个孩子
        else if(x->get_left()!=NULL&&x->get_right()!=NULL){
			//如果删除的是根结点
			if (x == root) {
				rm_root = true;
			}

			//处理与后继相连的点
			if (successor->flag) {
				//如果后继还有顶点
				successor->get_father()->set_right(successor->get_right());
				if(successor->get_right()!=NULL)
					successor->get_right()->set_father(successor->get_father());

			}
			else {
				successor->get_father()->set_left(successor->get_right());
				if(successor->get_left()!=NULL)
					successor->get_left()->set_father(successor->get_father());
			}

			successor->father = x->father;
			if (x->father) {
				if (flag) {
					x->father->right = successor;
				}
				else {
					x->father->left = successor;
				}
			}
			if (x->get_left() != NULL) {
				successor->set_left(x->get_left());
				x->get_left()->set_father(successor);
			}
			if (x->get_right()) {
				successor->set_right(x->get_right());
				x->get_right()->set_father(successor);
			}
			//root = successor;
			
        }

        //结点只有一个孩子
        else{

			if (x == root) {
				root = x->left == NULL ? x->right : x->left;
				root->father = NULL;
				delete x;
				return true;
			}
			if (x->get_left() != NULL) {
                if(flag && x->father!=NULL){
                    x->father->right = x->get_left();
                }else if(x->father != NULL){
                    x->father->left = x->get_left();
                }
				x->get_left()->set_father(x->get_father());
			}
			else {
                if(flag && x->father != NULL){
                    x->father->right = x->get_right();
                }else if(x->father != NULL){
                    x->father->left = x->get_right();
                }
				x->get_right()->set_father(x->get_father());
			}
        }

		if (rm_root) {
			root = successor;
		}
        delete x;
    }

    //中序便利
    void in_order_walk(node* r ){
        if(r!=NULL){
            in_order_walk(r->left);
            std::cout<<r->__key<<" ";
            in_order_walk(r->right);
        }
    }

	node* get_root() {
		return root;
	}

};

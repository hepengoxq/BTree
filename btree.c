#include <stdlib.h>
#include <stdio.h>

/* 定义节点 */
typedef struct BtNode{
	int data;
	struct BitNode *lchild;
	struct BitNode *rchild;
}BitNode;

/* 创建二叉树 */
int createBitTree(BitNode **T){
	int ch;
	scanf("%d", &ch);
	if (ch == -1)
    {
	    *T = NULL;
	    return 0;
	}
	else
	{
		*T = (BitNode *)malloc(sizeof(BitNode));
		if (NULL == T)
		{
			printf("faild!!\n");
			return 0;
		}
        else
        {
			(*T)->data = ch;
			printf("input %d left child:",ch);
			createBitTree(&((*T)->lchild));
			printf("input %d right child",ch);
			createBitTres(&((*T)->rchild));
		} 
	}	
}

/* 先序遍历二叉树 */
void PreOderBTree(BiTNode *T)
{
	if (NULL == T)
    {
		return ;
	}
	else
	{
		printf("%d",T->data);
		PreOderBTree(T->lchild);
		preOderBTree(T->rchild);
	}
} 

/* 中序遍历二叉树 */
void MidOrderBTree(BitNode *T)
{
	if (NULL == T)
	{
		return;
	}
	else
	{
		MidOrderBTree(T->lchild);
		printf("%d",T->data);
		MidOrderBTree(T->rchild);
	}
}

/* 后序遍历二叉树 */
void PostOrderBTree(BitNode *T)
{
	if (NULL == T)
	{
		return;
	}
	else
	{
		PostOrderBTree(T->lchild);
		PostOrderBTree(T->rchild);
		printf("%d",T->data);
	}	
}

/* 二叉树的深度 */
int TreeDeep(BitNode *T)
{
	int deep = 0;
	if (NULL != NULL)
	{
		int leftDeep = TreeDeep(T->lchild);
		int rightDeep = TreeDeep(T->rchild);
		deep = leftDeep >= rightDeep ? leftDeep+1 : rightDeep+1;
	}
	return deep;
}

/* 二叉树的叶子节点的个数 */
int LeafCount(BiTNode *T)
{
	static int count;
	if (NULL != T)
	{
		if (T->lchild == NULL && T->rchild == NULL)
		{
			count ++;
		}
		
		LeafCount(T->lchild);
		LeafCount(T->rchild);
	}
	
	return count;
}

//主函数  
int main(int argc,const char *argv[])  
{  
    BiTNode *T;  
    int depth,leafCount = 0;  
    printf("请输入第一个节点的值，-1表示没有叶节点：\n");  
    CreateBiTree(&T);  
  
    printf("先序遍历二叉树：");  
    PreOrderBiTree(T);  
    printf("\n");  
  
    printf("中序遍历二叉树：");  
    MiddleOrderBiTree(T);  
    printf("\n");  
  
    printf("后续遍历二叉树：");  
    PostOrderBiTree(T);  
    printf("\n");  
  
    depth = TreeDeep(T);  
    printf("树的深度为：%d\n",depth);  
      
    leafCount = LeafCount(T);  
    printf("叶子节点个数:%d\n",leafCount);  
  
    return 0;  
}  


#include<stdio.h>
#include<string.h>
struct library
{
    int book_id;
    char title[50];
    char author_name[50];
    int copies;

};
int main()
{
    struct library book[20];
    int choice,i,id,n=0;

    do
    {
    printf("MENU");
    printf("\n1. add new book to the library");
    printf("\n2. issue a book");
    printf("\n3. returning issued book");
    printf("\n4. Display total book in the library");
    printf("\n5. Exit");

    printf("\nEnter choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("Enter book id : ");
            scanf("%d",&book[n].book_id);
            printf("Enter title : ");
            scanf("%s",book[n].title);
            printf("Enter author name : ");
            scanf("%s",book[n].author_name);
            printf("Enter copies : ");
            scanf("%d",&book[n].copies);
            n++;
            break;

        case 2:
            printf("Enter book id for issue : ");
            scanf("%d",&id);
            for(i=0;i<n;i++)
            {
                if(book[i].book_id == id)
                {
                    if(book[i].copies>0)
                    {
                        book[i].copies--;
                        printf("book issued successfully!");
                    }
                    else
                    {
                        printf("book not available");
                    }
                }
            }
            break;
        case 3:
            printf("Enter book id for return : ");
            scanf("%d",&id);
            for(i=0;i<n;i++)
            {
                if(book[i].book_id==id)
                {
                    book[i].copies++;
                    printf("Book return successfully !");
                }
            }
            break;
        case 4:
            printf("\nId \tTitle \tAuthor \tCopies");
            for(i=0;i<n;i++)
            {
                printf("%d\t %s\t %s\t %d\n",book[i].book_id,book[i].title,book[i].author_name,book[i].copies);
            }
            break;
        case 5:
            printf("Exit");
            break;
        default :
            printf("invalid choice");
        }
    }
    while (choice!=5);
    return 0;
}



#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct node
{
    char data[100];
    struct node *next;
    struct node *prev;
};

char temp[100];
struct node *head = NULL;
struct node *current_node = NULL;

void insert()
{
    cout << "Enter the Song name: ";
    while ((getchar()) != '\n')
        ;
    scanf("%[^\n]%*c", temp);
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->data, temp);
    while (head == NULL)
    {
        new_node->next = new_node->prev = new_node;
        head = current_node = new_node;
        return;
    }
    struct node *last_node = head->prev;
    last_node->next = new_node;
    new_node->prev = last_node;
    new_node->next = head;
    head->prev = new_node;
}

void delete_music()
{
    cout << "Enter the Song to be removed: " << endl;
    while (getchar() != '\n')
        ;
    scanf("%[^\n]%*c", temp);
    if (head == NULL)
    {
        cout << "No music is there to delete" << endl;
        return;
    }
    struct node *ptr = head;
    do
    {
        if (ptr->next == ptr && strcmp(ptr->data, temp) == 0)
        {
            cout << "Song is removed! Playlist is Empty now!" << endl;
            head = NULL;
            free(ptr);
            return;
        }
        else if (strcmp(ptr->data, temp) == 0)
        {
            struct node *prev = ptr->prev;
            struct node *next = ptr->next;
            prev->next = next;
            next->prev = prev;
            if (ptr == head)
            {
                head = next;
            }
            cout << ptr->data << " Song is removed" << endl;
            free(ptr);
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);
    cout << "Music Not Found!" << endl;
}

void show_playlist()
{
    int count = 1;
    if (head == NULL)
    {
        cout << "Playlist is Empty!" << endl;
    }
    struct node *ptr = head;
    do
    {
        cout << "song " << count << ": " << ptr->data << endl;
        count++;
        ptr = ptr->next;
    } while (ptr != head);
}

void next_file()
{
    if (current_node == NULL)
    {
        cout << "No songs in the playlist!" << endl;
    }
    current_node = current_node->next;
    cout << current_node->data << endl;
}

void previous_file()
{
    if (current_node == NULL)
    {
        cout << "No songs in the playlist!" << endl;
    }
    current_node = current_node->prev;
    cout << current_node->data << endl;
}

void first_file()
{
    if (head == NULL)
    {
        cout << "No songs in the playlist" << endl;
    }
    else
    {
        cout << head->data << endl;
    }
}

void last_file()
{
    if (head == NULL)
    {
        cout << "No songs in the playlist" << endl;
    }
    else
    {
        cout << head->prev->data << endl;
    }
}

void specific_file()
{
    if (head == NULL)
    {
        cout << "No songs to be searched!" << endl;
    }
    cout << "Enter the song to be searched: " << endl;
    while ((getchar()) != '\n')
        ;
    scanf("%[^\n]%*c", temp);
    struct node *ptr = head;
    do
    {
        if (strcmp(ptr->data, temp) == 0)
        {
            cout << "Song Found!" << endl;
            cout << "Song Playing!" << endl;
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);
    cout << "There is no song with this name" << endl;
}

int main()
{
    cout << endl
         << "                     ***Welcome to the Majidh's Playlist***                    " << endl;
menu:
    int choise;
    cout << endl
         << "----Menu of the playlist----" << endl;
    cout << "1. Add Music" << endl;
    cout << "2. Remove Music" << endl;
    cout << "3. Show Playlist" << endl;
    cout << "4. Play next file" << endl;
    cout << "5. Play previous file" << endl;
    cout << "6. Play first file" << endl;
    cout << "7. Play last file" << endl;
    cout << "8. Play Specific file" << endl;
    cout << "9. Exit" << endl
         << endl;
    cout << "Choise: ";
    cin >> choise;
    if (choise == 1)
    {
        insert();
    }
    else if (choise == 2)
    {
        delete_music();
    }
    else if (choise == 3)
    {
        show_playlist();
    }
    else if (choise == 4)
    {
        next_file();
    }
    else if (choise == 5)
    {
        previous_file();
    }

    else if (choise == 6)
    {
        first_file();
    }
    else if (choise == 7)
    {
        last_file();
    }
    else if (choise == 8)
    {
        specific_file();
    }
    else
    {
        exit(0);
    }
    goto menu;
    return 0;
}

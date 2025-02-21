#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song_t {
    char title[100];
    struct Song_t* next;
};

typedef struct Song_t Song;

Song* head = NULL;

void addSong(int n);
void nextSong();
void displayCurrentSong();

int main() {
    int choice;
    
    do {
        printf("\nPlaylist Management System\n");
        printf("1. Add song\n2. Next song\n3. Display current song\n");
        printf("Enter your operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int n;
                printf("Enter number of songs to add: ");
                scanf("%d", &n);
                addSong(n);
                break;
            }
            case 2: {
                nextSong();
                break;
            }
            case 3: {
                displayCurrentSong();
                break;
            }
            default: {
                printf("Exiting Playlist Management...\n");
            }
        }
    } while ((choice >= 1) &&(choice <=3));
    return 0;
}

void addSong(int n) {
    char songTitle[100];
    
    for (int i = 0; i < n; i++) {
        printf("Enter song title %d: ", i + 1);
        scanf(" %s", songTitle);
        
        Song* newSong = (Song*)malloc(sizeof(Song));
        strcpy(newSong->title, songTitle);

        if (head == NULL) {
            head = newSong;
            newSong->next = head;
        } else {
            Song* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newSong;
            newSong->next = head;
        }
    }
}

void nextSong() {
    if (head == NULL) {
        printf("No songs in the playlist.\n");
        return;
    }
    head = head->next;
    displayCurrentSong();
}

void displayCurrentSong() {
    if (head == NULL) {
        printf("No songs in the playlist.\n");
        return;
    }
    printf("Current Song: %s\n", head->title);
}

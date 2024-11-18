// FolderTest.cpp
#include "gtest/gtest.h"
#include "../src/Folder.h"


// Test per il costruttore di Folder
TEST(FolderTest, Constructor) {
    Folder folder("TestFolder");
    ASSERT_EQ(folder.getName(), "TestFolder");
}

// Test per aggiungere una nota
TEST(FolderTest, AddNote) {
    Folder folder("TestFolder");
    Note note1("Title1", "Content1");

    ASSERT_TRUE(folder.addNote(note1));
    ASSERT_EQ(folder.getSize(), 1);
}

// Test per rimuovere una nota
TEST(FolderTest, RemoveNote) {
    Folder folder("TestFolder");
    Note note1("Title1", "Content1");

    folder.addNote(note1);
    ASSERT_TRUE(folder.removeNote("Title1"));
    ASSERT_EQ(folder.getSize(), 0);
}

// Test per trovare una nota dal titolo
TEST(FolderTest, GetNoteFromTitle) {
    Folder folder("TestFolder");
    Note note1("Title1", "Content1");

    folder.addNote(note1);
    Note foundNote("", "");
    ASSERT_TRUE(folder.getNoteFromTitle("Title1", foundNote));
    ASSERT_EQ(foundNote.getTitle(), "Title1");
}

// Test per cambiare il titolo di una nota non bloccata
TEST(FolderTest, ChangeTitle) {
    Folder folder("TestFolder");
    Note note1("Title1", "Content1");

    folder.addNote(note1);
    folder.changeTitle(note1, "NewTitle1");
    ASSERT_EQ(note1.getTitle(), "NewTitle1");
}

// Test per cambiare il testo di una nota non bloccata
TEST(FolderTest, ChangeText) {
    Folder folder("TestFolder");
    Note note1("Title1", "Content1");

    folder.addNote(note1);
    folder.changeText(note1, "NewContent1");
    ASSERT_EQ(note1.getContent(), "NewContent1");
}

// Test per bloccare una nota
TEST(FolderTest, BlockNote) {
    Folder folder("TestFolder");
    Note note1("Title1", "Content1");

    folder.blockNote(note1);
    ASSERT_TRUE(note1.isLocked());
}

// Test per sbloccare una nota
TEST(FolderTest, UnlockNote) {
    Folder folder("TestFolder");
    Note note1("Title1", "Content1");

    folder.blockNote(note1);
    ASSERT_TRUE(note1.isLocked());

    folder.unlockNote(note1);
    ASSERT_FALSE(note1.isLocked());
}

// Test per aggiungere una nota ai preferiti
TEST(FolderTest, MakeFavourite) {
    Folder folder("TestFolder");
    Note note1("Title1", "Content1");

    ASSERT_TRUE(folder.makeFavourite(note1));
    ASSERT_TRUE(note1.isFavorite());
}

// Test per ottenere una lista di tutte le note (titolo e cartella)
TEST(FolderTest, GetAllNotesList) {
    Folder folder("TestFolder");
    Note note1("Title1", "Content1");
    Note note2("Title2", "Content2");

    folder.addNote(note1);
    folder.addNote(note2);

    auto notes = folder.getAllNotesList();
    ASSERT_EQ(notes.size(), 2);
}

// Test per cercare note che contengono una parola chiave
TEST(FolderTest, FindNotes) {
    Folder folder("TestFolder");
    Note note1("Important", "This is important");
    Note note2("Title2", "Just another content");

    folder.addNote(note1);
    folder.addNote(note2);

    auto results = folder.findNotes("important");
    ASSERT_EQ(results.size(), 1);
    ASSERT_EQ(results.front().getTitle(), "Important");
}

// Test per rimuovere una nota dai preferiti
TEST(FolderTest, RemoveFavorite) {
    Folder folder("TestFolder");
    Note note1("Title1", "Content1");
    folder.addNote(note1);

    Note folderNote("Title1", "Content1");
    folder.getNoteFromTitle("Title1", folderNote);

    folder.makeFavourite(folderNote);
    ASSERT_TRUE(folderNote.isFavorite());

    ASSERT_TRUE(folder.removeFavorite("Title1"));

    folder.getNoteFromTitle("Title1", folderNote);
    ASSERT_FALSE(folderNote.isFavorite());
}

// Test per ottenere la lista delle note preferite
TEST(FolderTest, ListFavorites) {
    Folder folder("TestFolder");
    folder.addNote(Note("Title1", "Content1"));
    folder.addNote(Note("Title2", "Content2"));

    Note folderNote1("Title1", "Content1");
    Note folderNote2("Title2", "Content2");

    // si recuperano le note dal folder
    folder.getNoteFromTitle("Title1", folderNote1);
    folder.getNoteFromTitle("Title2", folderNote2);

    folder.makeFavourite(folderNote1);
    folder.makeFavourite(folderNote2);

    // aggiorna le note nel folder
    folder.removeNote("Title1");
    folder.removeNote("Title2");
    folder.addNote(folderNote1);
    folder.addNote(folderNote2);

    auto favorites = folder.listFavorites();
    ASSERT_EQ(favorites.size(), 2);
}

// Test per ottenere la lista delle note bloccate
TEST(FolderTest, ListBlocked) {
    Folder folder("TestFolder");
    folder.addNote(Note("Title1", "Content1"));
    folder.addNote(Note("Title2", "Content2"));

    Note folderNote1("Title1", "Content1");
    Note folderNote2("Title2", "Content2");

    // recupera le note dal folder
    folder.getNoteFromTitle("Title1", folderNote1);
    folder.getNoteFromTitle("Title2", folderNote2);

    // poi le blocca
    folder.blockNote(folderNote1);
    folder.blockNote(folderNote2);

    // aggiorna le note nel folder
    folder.removeNote("Title1");
    folder.removeNote("Title2");
    folder.addNote(folderNote1);
    folder.addNote(folderNote2);

    auto blocked = folder.listBlocked();
    ASSERT_EQ(blocked.size(), 2);
    ASSERT_TRUE(std::find_if(blocked.begin(), blocked.end(),
                             [&](const Note& n){ return n.getTitle() == "Title1"; }) != blocked.end());
    ASSERT_TRUE(std::find_if(blocked.begin(), blocked.end(),
                             [&](const Note& n){ return n.getTitle() == "Title2"; }) != blocked.end());
}

// Test per modificare il testo di una nota
TEST(FolderTest, EditNoteText) {
    Folder folder("TestFolder");
    Note note1("Title1", "Content1");

    folder.addNote(note1);
    ASSERT_TRUE(folder.editNoteText(note1, "NewContent1"));
    ASSERT_EQ(note1.getContent(), "NewContent1");
}

// Test per modificare il titolo di una nota
TEST(FolderTest, EditNoteTitle) {
    Folder folder("TestFolder");
    Note note1("Title1", "Content1");

    folder.addNote(note1);
    ASSERT_TRUE(folder.editNoteTitle(note1, "NewTitle1"));
    ASSERT_EQ(note1.getTitle(), "NewTitle1");
}
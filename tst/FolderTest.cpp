#include "gtest/gtest.h"
#include "../src/Folder.h"
#include "../src/Note.h"
#include "../src/Observer.h"

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

// Test per aggiungere una nota ai preferiti
TEST(FolderTest, MakeFavourite) {
    Folder folder("TestFolder");
    Note note1("Title1", "Content1");

    ASSERT_TRUE(Folder::makeFavourite(note1));
    ASSERT_TRUE(note1.isFavorite());
}

// Test per rimuovere una nota dai preferiti

TEST(FolderTest, RemoveFavorite) {
    Folder folder("TestFolder");
    Note note1("Title1", "Content1");

    // Aggiungi la nota al folder prima di marcarla come preferita
    folder.addNote(note1); // Aggiungi la nota al folder

    // Mark the note as favorite
    ASSERT_TRUE(folder.makeFavourite(note1)); // Usa folder.makeFavourite per aggiungere la nota
    ASSERT_TRUE(folder.removeFavorite("Title1")); // Rimuovi dai preferiti

    // Verifica che la nota non sia più nei preferiti
    ASSERT_FALSE(note1.isFavorite()); // Controlla che il flag sia ora false
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


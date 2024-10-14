#include <gtest/gtest.h>
#include "../src/Note.h"

TEST(NoteTest, ConstructorTest) {
    Note note("Test Title", "Test Content", true);
    EXPECT_EQ(note.getTitle(), "Test Title");  // Dovrebbe avere il titolo "Test Title"
    EXPECT_EQ(note.getContent(), "Test Content"); // Dovrebbe avere il contenuto "Test Content"
    EXPECT_TRUE(note.isLocked()); // Dovrebbe essere bloccato
    EXPECT_FALSE(note.isFavorite()); // Non dovrebbe essere un preferito
}

TEST(NoteTest, SettersTest) {
    Note note("Test Title", "Test Content");

    note.setTitle("New Title");
    EXPECT_EQ(note.getTitle(), "New Title"); // Dovrebbe cambiare il titolo

    note.lock();
    note.setContent("New Content");
    EXPECT_EQ(note.getContent(), "Test Content"); // Non dovrebbe cambiare il contenuto perché la nota è bloccata
}

TEST(NoteTest, FavoritesTest) {
    Note note("Test Title", "Test Content");
    note.addToFavorites();
    EXPECT_TRUE(note.isFavorite());  // Dovrebbe essere un preferito

    note.lock();
    note.removeFromFavorites();
    EXPECT_TRUE(note.isFavorite()); // Dovrebbe ancora essere un preferito perché la nota è bloccata
}

TEST(NoteTest, EqualityOperatorTest) {
    Note note1("Title", "Content");
    Note note2("Title", "Content");
    Note note3("Different Title", "Content");

    EXPECT_TRUE(note1 == note2); // Dovrebbero essere uguali
    EXPECT_FALSE(note1 == note3); // Dovrebbero essere diversi
}
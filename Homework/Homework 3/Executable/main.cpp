#include <iostream>
#include <string>
#include <vector>
#include <string>
#include "word_counter.h"
#include "parallel_task.h"

std::vector<std::string> gettysburg_address = { "Four", "score", "and", "seven", "years", "ago", "our", "fathers", "brought",
                                               "forth", "on", "this", "continent", "a", "new", "nation", "conceived", "in",
                                               "Liberty", "and", "dedicated", "to", "the", "proposition", "that", "all", "men",
                                               "are", "created", "equal", "Now", "we", "are", "engaged", "in", "a", "great", "civil",
                                               "war", "testing", "whether", "that", "nation", "or", "any", "nation", "so", "conceived",
                                               "and", "so", "dedicated", "can", "long", "endure", "We", "are", "met", "on", "a", "great",
                                               "battle-field", "of", "that", "war", "We", "have", "come", "to", "dedicate", "a", "portion",
                                               "of", "that", "field", "as", "a", "final", "resting", "place", "for", "those", "who", "here",
                                               "gave", "their", "lives", "that", "that", "nation", "might", "live", "It", "is", "altogether",
                                               "fitting", "and", "proper", "that", "we", "should", "do", "this", "But", "in", "a", "larger",
                                               "sense", "we", "can", "not", "dedicate", "we", "can", "not", "consecrate", "we", "can", "not",
                                               "hallow", "this", "ground", "The", "brave", "men", "living", "and", "dead", "who", "struggled",
                                               "here", "have", "consecrated", "it", "far", "above", "our", "poor", "power", "to", "add", "or",
                                               "detract", "The", "world", "will", "little", "note", "nor", "long", "remember", "what", "we", "say",
                                               "here", "but", "it", "can", "never", "forget", "what", "they", "did", "here", "It", "is", "for", "us",
                                               "the", "living", "rather", "to", "be", "dedicated", "here", "to", "the", "unfinished", "work", "which",
                                               "they", "who", "fought", "here", "have", "thus", "far", "so", "nobly", "advanced", "It", "is", "rather",
                                               "for", "us", "to", "be", "here", "dedicated", "to", "the", "great", "task", "remaining", "before", "us",
                                               "that", "from", "these", "honored", "dead", "we", "take", "increased", "devotion", "to", "that", "cause",
                                               "for", "which", "they", "gave", "the", "last", "full", "measure", "of", "devotion", "that", "we", "here",
                                               "highly", "resolve", "that", "these", "dead", "shall", "not", "have", "died", "in", "vain", "that", "this",
                                               "nation", "under", "God", "shall", "have", "a", "new", "birth", "of", "freedom", "and", "that", "government",
                                               "of", "the", "people", "by", "the", "people", "for", "the", "people", "shall", "not", "perish", "from", "the", "earth" };

void verify_word_count(const std::string&, int);

int main()
{
    verify_word_count("earth", 1);
    verify_word_count("four", 1);
    verify_word_count("is", 3);
    verify_word_count("it", 5);
    verify_word_count("we", 10);

    std::cout << "Press any key to continue...\n";
    std::getchar();
}

void verify_word_count(const std::string& word, int expected_count)
{
    word_counter counter;

    auto task = make_parallel_task(gettysburg_address.begin(), gettysburg_address.end(), counter, word, 4);
    task.start();
    task.complete();

    if (counter.get_count() == expected_count)
        std::cout << "Correct - found \"" << word << "\" " << expected_count << " times\n";
    else
        std::cout << "Incorrect - looking for \"" << word << "\" expected: " << expected_count << " actual: " << counter.get_count() << std::endl;
}

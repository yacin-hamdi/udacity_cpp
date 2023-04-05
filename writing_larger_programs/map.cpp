#include<iostream>
#include<vector>
#include<unordered_map>


int main() {
	std::string key{ "word" };
	std::string def1 ="a unit of language, consisting of one or more spoken sounds or their writtenrepresentation,that functions as a principal carrier of meaning.";
	std::string def2 = "speech or talk: to express one's emotion in words.";
	std::string def3 = "a short talk or conversation: \"Marston, I'd like a word with you.\"";
	std::string def4 = "an expression or utterance: a word of warning.";
	std::unordered_map<std::string, std::vector<std::string>> my_dic;

	if (my_dic.find(key) == my_dic.end()) {
		std::cout << "the key 'word' is not in the dictionary\n";
		std::cout << "insert key:value pair into the dictionary\n\n";
		my_dic[key] = std::vector<std::string>{ def1, def2, def3, def4 };

	}

	std::cout << key << "\n";
	std::vector<std::string> definitions = my_dic[key];

	for (std::string definition : definitions) {
		std::cout << definition << "\n";
	}

	std::cout << "\n\n\n";

	std::unordered_map<int, std::string> person = { {23, "jendouba"},
		{45, "tunis"},
		{576, "israel"},
		{ 1, "usa"},
		{46, "london"} };

	if (person.find(34) == person.end()) {
		person[34] = "egypt";
	}

	std::vector<int> ids{ 1, 23, 34, 45, 46, 576 };

	for (int id : ids) {
		std::cout << person[id] << "\n";
	}

	

}
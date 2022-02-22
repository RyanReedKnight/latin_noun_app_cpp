#include"latin_noun.h"
#include<iostream>
#include<string>
#include<stdexcept>

#include"str_case.h"

using std::string;	using std::domain_error;

typedef string::size_type str_sz;

// Global variables
	// Masculine sufixes
string us = "us";	string um = "um";	string i = "i";	string o = "o";
string os = "os";	string orum = "orum";	string is = "is";
	// Feminine sufixes
string a = "a";	string am = "am";	string ae = "ae";	string as = "as";	string arum = "arum";
	// Genders
string masc = "masculine";	string femn = "feminine";	string neut = "neuter";

// Setters
	// Singular declensions
void Latin_noun::set_nom_sng(const string& nom_sng) { this->nom_sng = string(nom_sng); }
void Latin_noun::set_acc_sng(const string& acc_sng) { this->acc_sng = string(acc_sng); }
void Latin_noun::set_gen_sng(const string& gen_sng) { this->gen_sng = string(gen_sng); }
void Latin_noun::set_dat_sng(const string& dat_sng) { this->dat_sng = string(dat_sng); }
void Latin_noun::set_abl_sng(const string& abl_sng) { this->abl_sng = string(abl_sng); }
	// Plural declensions
void Latin_noun::set_nom_plr(const string& nom_plr) { this->nom_plr = string(nom_plr); }
void Latin_noun::set_acc_plr(const string& acc_plr) { this->acc_plr = string(acc_plr); }
void Latin_noun::set_gen_plr(const string& gen_plr) { this->gen_plr = string(gen_plr); }
void Latin_noun::set_dat_plr(const string& dat_plr) { this->dat_plr = string(dat_plr); }
void Latin_noun::set_abl_plr(const string& abl_plr) { this->abl_plr = string(abl_plr); }
	// Noun gender
void Latin_noun::set_gender(const string& gender) { this->gender = string(gender); }
// Getters
	// Singular declensions
string Latin_noun::get_nom_sng() { return this->nom_sng; }
string Latin_noun::get_acc_sng() { return this->acc_sng; }
string Latin_noun::get_gen_sng() { return this->gen_sng; }
string Latin_noun::get_dat_sng() { return this->dat_sng; }
string Latin_noun::get_abl_sng() { return this->abl_sng; }
	// Plural declensions
string Latin_noun::get_nom_plr() { return this->nom_plr; }
string Latin_noun::get_acc_plr() { return this->acc_plr; }
string Latin_noun::get_gen_plr() { return this->gen_plr; }
string Latin_noun::get_dat_plr() { return this->dat_plr; }
string Latin_noun::get_abl_plr() { return this->abl_plr; }
	// Noun gender
string Latin_noun::get_gender() { return this->gender; }

void Latin_noun::set_all(const string& nom_sng, const string& nom_sng_sfx, const string& acc_sng_sfx, 
	const string& gen_sng_sfx, const string& dat_sng_sfx, const string& abl_sng_sfx, const string& nom_plr_sfx,
	const string& acc_plr_sfx, const string& gen_plr_sfx, const string& dat_plr_sfx, const string& abl_plr_sfx) {

	str_sz sfx_len = nom_sng_sfx.size();
	str_sz stem_len = nom_sng.size() - sfx_len;
	this->stem = string(nom_sng.substr(0, stem_len));

	// Set singular sufixes 
	this->nom_sng = string(this->stem + nom_sng_sfx);
	this->acc_sng = string(this->stem + acc_sng_sfx);
	this->gen_sng = string(this->stem + gen_sng_sfx);
	this->dat_sng = string(this->stem + dat_sng_sfx);
	this->abl_sng = string(this->stem + abl_sng_sfx);
	// Set plural sufixes
	this->nom_plr = string(this->stem + nom_plr_sfx);
	this->acc_plr = string(this->stem + acc_plr_sfx);
	this->gen_plr = string(this->stem + gen_plr_sfx);
	this->dat_plr = string(this->stem + dat_plr_sfx);
	this->abl_plr = string(this->stem + abl_plr_sfx);
}
void Latin_noun::set_all_masc(const string& nom_sng) {
	set_all(nom_sng, us, um, i, o, o, i, os, orum, is, is);
	this->gender = string(masc);
}
void Latin_noun::set_all_neut(const string& nom_sng) {
	set_all(nom_sng, um, um, i, o, o, a, a, orum, is, is);
	this->gender = string(neut);
}
void Latin_noun::set_all_femn(const string& nom_sng) {
	set_all(nom_sng, a, am, ae, ae, a, ae, as, arum, is, is);
	this->gender = string(femn);
}
// to_string() method.
string Latin_noun::to_string() {

	string singular("Singular"),nominative("Nominavtive:  "),accusative("Accusative:  "),genative("Genative:  "),
		dative("Dative: "), ablative("Ablative:  "), nl("\n");

	str_sz left_len = (this->acc_sng.size() > (singular.size())) ? this->acc_sng.size() : singular.size();


	string ret = string(nominative.size(),' ') + singular + string(left_len-singular.size()+2,' ') + "Plural\n"
		+ nominative + this->nom_sng + str_diff(left_len,this->nom_sng.size(),2) + this->nom_plr + nl
		+ accusative + str_diff(nominative.size(),accusative.size(),0) + this->acc_sng + str_diff(left_len, this->acc_sng.size(), 2) + this->acc_plr +nl
		+ genative + str_diff(nominative.size(),genative.size(),0) + this->gen_sng + str_diff(left_len,this->gen_sng.size(),2) + this->gen_plr + nl
		+ dative + str_diff(nominative.size(), dative.size(), 0) + this->dat_sng + str_diff(left_len, this->dat_sng.size(), 2) + this->dat_plr + nl
		+ ablative + str_diff(nominative.size(), ablative.size(), 0) + this->abl_sng + str_diff(left_len, this->abl_sng.size(), 2) + this->abl_plr + nl + nl
		+ "Gender: " + this->gender + nl;

	return ret;
}

// str_diff, helps in to_string method.
string Latin_noun::str_diff(string::size_type longer, string::size_type shorter, string::size_type n) {
	return string(longer-shorter + n,' ');
}

// Constructor
Latin_noun::Latin_noun(const string& nom_sng_) {
	str_sz len = nom_sng_.size();
	const string nom_sng = str_tolower_rtn(nom_sng_);

	// Check to see if noun is masculine, if so, append masculine suffixes.
	if (0==nom_sng.substr(len - us.size(), len).compare(us)) {
		set_all_masc(nom_sng);
	}
	// Check if noun is feminine, if so, append masculine suffixes.
	else if(0==nom_sng.substr(len-a.size(),len).compare(a)){
		set_all_femn(nom_sng);
	}
	// Check if noun is neuter, if so, append masculine suffixes.
	else if (0==nom_sng.substr(len-um.size(),len).compare(um)) {
		set_all_neut(nom_sng);
	}else throw domain_error("Latin_noun class can only handle first and" 
			" second declension nouns and adjectives.");
}


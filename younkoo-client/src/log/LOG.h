#pragma once


#include <iostream>
#ifdef LOG
#undef LOG
#endif // LOG

//#define DEBUG
#ifdef DEBUG
#define LOG(STR) std::cout << "[BaierOops]" << STR << std::endl
#define LOG_N(STR) std::cout << "[BaierOops]" << STR
#define FLUSH() std::cout.flush
#define LOG_P(PREFIX,STR) std::cout << "["<<PREFIX<<"]" << STR << std::endl
#define LOG_FIELD(FIELD) LOG_N("[BaierOops]" <<#FIELD  << " :" << FIELD << std::endl);
#define LOG_FIELD_HEX(FIELD) LOG_N("[BaierOops]" <<#FIELD  << " :" <<std::hex  << FIELD << std::dec << std::endl);
#define LOG_FIELD_P(PREFIX,FIELD) LOG_N("["<<PREFIX<<"]" << #FIELD << " :"<< FIELD << std::endl);
#define LOG_FIELD_HEX_P(PREFIX,FIELD) LOG_N("["<<PREFIX<<"]" << #FIELD << " :"<< std::hex  << FIELD <<std::dec << std::endl);
#define LOG_HEX(NAME,HEX) LOG_N("[BaierOops]" <<NAME << std::hex << HEX << std::dec << std::endl);
#define LOG_HEX_P(PREFIX,NAME,HEX) LOG_N("["<<PREFIX<<"]" << NAME << std::hex << HEX << std::dec << std::endl);
#else 
#define LOG(STR)
#define LOG_N(STR)
#define FLUSH()
#define LOG_P(PREFIX,STR)
#define LOG_FIELD(FIELD)
#define LOG_FIELD_HEX(FIELD)
#define LOG_FIELD_P(PREFIX,FIELD)
#define LOG_FIELD_HEX_P(PREFIX,FIELD)
#define LOG_HEX(HEX)
#define LOG_HEX_P(PREFIX,NAME,HEX) LOG_N("["<<PREFIX<<"]" << NAME << std::hex << HEX << std::dec << std::endl);
#endif
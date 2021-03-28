#include "test_runner.h"

#include <array>
#include <cstddef>
#include <cstdint>

const std::array<bool, 2> bool_array = {false, true};
const std::array<char, 4> char_array = {'A', 'C', 'G', 'T'};

struct Nucleotide {
  char Symbol; // 		1 1
  size_t Position; //	4 2
  int ChromosomeNum; // 4 1 (6 bit)
  int GeneNum; // 		4 2	(15 bit)
  bool IsMarked; //		1 1
  char ServiceInfo; //	1 1
};


struct CompactNucleotide {
  uint32_t Position; //	4 2
  uint16_t GeneNum:15; // 		4 2	(15 bit)
  uint16_t IsMarked:1; //		1 1 (1 bit)
  uint8_t ChromosomeNum:6; // 4 1 (6 bit)
  uint8_t Symbol:2; // 		1 1 (2 bit)
  char ServiceInfo; //	1 1

};


bool operator == (const Nucleotide& lhs, const Nucleotide& rhs) {
  return (lhs.Symbol == rhs.Symbol)
      && (lhs.Position == rhs.Position)
      && (lhs.ChromosomeNum == rhs.ChromosomeNum)
      && (lhs.GeneNum == rhs.GeneNum)
      && (lhs.IsMarked == rhs.IsMarked)
      && (lhs.ServiceInfo == rhs.ServiceInfo);
}



CompactNucleotide Compress(const Nucleotide& n) {
	uint8_t num;
	if (n.Symbol == 'A') {
		num = 0;
	} else if (n.Symbol == 'C') {
		num = 1;
	} else if (n.Symbol == 'G') {
		num = 2;
	} else if (n.Symbol == 'T') {
		num = 3;
	}
  return {n.Position,
	  	  n.GeneNum,
		  n.IsMarked,
	  	  n.ChromosomeNum,
	  	  num,
	  	  n.ServiceInfo
  };
}


Nucleotide Decompress(const CompactNucleotide& cn) {
	  return {char_array[cn.Symbol],
		  	  cn.Position,
		  	  cn.ChromosomeNum,
			  cn.GeneNum,
			  bool_array[cn.IsMarked],
			  cn.ServiceInfo
	  };
}

void TestSize() {
  ASSERT(sizeof(CompactNucleotide) <= 8);
}

void TestCompressDecompress() {
  Nucleotide source;

  source.Symbol = 'T';
  source.Position = 1'000'000'000;
  source.ChromosomeNum = 48;
  source.GeneNum = 1'000;
  source.IsMarked = true;
  source.ServiceInfo = 'e';

  CompactNucleotide compressedSource = Compress(source);
  Nucleotide decompressedSource = Decompress(compressedSource);
  ASSERT(source == decompressedSource);
}

int main() {
  TestRunner tr;

  RUN_TEST(tr, TestSize);
  RUN_TEST(tr, TestCompressDecompress);

  return 0;
}

#ifndef _TESTINGH
#define _TESTINGH
#ifdef INFORMATION
Copyright (C)2011-2022 by Bruce Wilcox

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#endif
#define HAS_BREAKPOINTS 2
#define TESTING_REPEATALLOWED 1000
extern unsigned int priortrace;

void InitStats();
extern char priorLogin[ID_SIZE];

#ifndef DISCARDTESTING

typedef void (*COMMANDPTR)(char* input);

typedef struct CommandInfo 
{
	char* word;			// dictionary word entry
	COMMANDPTR fn;				// function to use to get it
	char* comment;		// what to say about it
} CommandInfo;

extern CommandInfo commandSet[];
extern int breakIndex;
TestMode Command(char* input,char* output,bool fromScript);
int CountSet(WORDP D,unsigned int baseStamp);
extern bool nomixedcase;
extern bool noconcept;
void Sortit(char* name,int oneline);
void SortTopic(WORDP D,uint64 junk);
void SortTopic0(WORDP D,uint64 junk);
void C_MemStats(char* input);
#endif

TestMode DoCommand(char* input,char* output,bool authorize=true);
bool VerifyAuthorization(FILE* in);

// Exposed for unit testing

struct IngestStruct {
    char* readbuf;              /* working buffer for parsing log entry */
    char* buffer;               /* input to PerformChat parsed from log */
    char* outbuffer;            /* output generated by PerformChat */
    char expectedWhy[MAX_WORD_SIZE];
    char actualWhy[MAX_WORD_SIZE];
    char bot[MAX_WORD_SIZE];
    char lastCategory[100];
    char lastSpecialty[100];
    char user[MAX_WORD_SIZE];
    char ip[100];
    char label[MAX_WORD_SIZE];
    char topic[MAX_WORD_SIZE];
    char turn[100];
    char* output;               /* output parsed from log */
    char* expectedOutput;       /* cleaned version from log  */
    char* actualOutput;         /* cleaned version from PerformChat */
};
void mallocIngestStruct(IngestStruct& is, int limit);
void freeIngestStruct(IngestStruct& is);
bool parseIngestLogEntry(IngestStruct& is);
char* CleanLogEntry(char* output);

#endif

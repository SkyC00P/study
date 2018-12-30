#include "MGraph.h"
#include "test.h"

static MGraph dgMGraph;
static MGraph dnMGraph;
static MGraph udgMGraph;
static MGraph udnMGraph;

static void test();

int main() {
	test();
	TEST_REPORT;
}

static void test() {
	puts("(1) 测试有向图");
	FILE * dg_fp = fopen("MGraph/test_data/DG.txt", "r");
	if (dg_fp) {
		dgMGraph = MGraph_create(dg_fp);
		EXPECT_TRUE(dgMGraph != NULL);
		fclose(dg_fp);
		MGraph_print(dgMGraph);
	}
	else {
		LOG("IO ERR");
		EXPECT_TRUE(0);
	}

	puts("(2) 测试有向网");
	FILE * dn_fp = fopen("MGraph/test_data/DN.txt", "r");
	if (dn_fp) {
		dnMGraph = MGraph_create(dn_fp);
		EXPECT_TRUE(dnMGraph != NULL);
		fclose(dn_fp);
		MGraph_print(dnMGraph);
	}
	else {
		LOG("IO ERR");
		EXPECT_TRUE(0);
	}

	puts("(3) 测试无向图");
	FILE * udg_fp = fopen("MGraph/test_data/UDG.txt", "r");
	if (udg_fp) {
		udgMGraph = MGraph_create(udg_fp);
		EXPECT_TRUE(udgMGraph != NULL);
		fclose(udg_fp);
		MGraph_print(udgMGraph);
	}
	else {
		LOG("IO ERR");
		EXPECT_TRUE(0);
	}

	puts("(4) 测试无向图");
	FILE * udn_fg = fopen("MGraph/test_data/UDN.txt", "r");
	if (udn_fg) {
		udnMGraph = MGraph_create(udn_fg);
		EXPECT_TRUE(udnMGraph != NULL);
		fclose(udn_fg);
		MGraph_print(udnMGraph);
	}
	else {
		LOG("IO ERR");
		EXPECT_TRUE(0);
	}
}
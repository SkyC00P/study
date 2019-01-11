#include "MGraph.h"
#include "test.h"

static MGraph dgMGraph;
static MGraph dnMGraph;
static MGraph udgMGraph;
static MGraph udnMGraph;

static void test();

static void test_udn_mgraph_add_and_del();

static void test_udg_mgraph_add_and_del();

static void test_dn_mgraph_add_and_del();

static void test_dg_mgraph_add_and_del();

int main() {
	test();
	TEST_REPORT;
}

/*
	测试点:
	1. 图初始化

*/
static void test() {
	puts("(1) 测试有向图");
	FILE * dg_fp = fopen("test_data/DG.txt", "r");
	if (dg_fp) {
		dgMGraph = MGraph_create(dg_fp);
		EXPECT_TRUE(dgMGraph != NULL);
		fclose(dg_fp);
		MGraph_print(dgMGraph);

		EXPECT_TRUE(MGraph_locate(dgMGraph, 'C') == 2);
		EXPECT_TRUE(MGraph_get(dgMGraph, 2) == 'C');
		EXPECT_TRUE(MGraph_frist_vertex(dgMGraph, 'B') == 2);
		EXPECT_TRUE(MGraph_next_vertex(dgMGraph, 'A', 'B') == 3);

		puts("深度遍历图:预期为ABCD");
		MGraph_DFS(dgMGraph);
		puts("广度遍历图");
		MGraph_HFS(dgMGraph);

		test_dg_mgraph_add_and_del();
	}
	else {
		LOG("IO ERR");
		EXPECT_TRUE(0);
	}

	puts("(2) 测试有向网");
	FILE * dn_fp = fopen("test_data/DN.txt", "r");
	if (dn_fp) {
		dnMGraph = MGraph_create(dn_fp);
		EXPECT_TRUE(dnMGraph != NULL);
		fclose(dn_fp);
		MGraph_print(dnMGraph);

		EXPECT_TRUE(MGraph_locate(dnMGraph, 'C') == 2);
		EXPECT_TRUE(MGraph_get(dnMGraph, 2) == 'C');
		EXPECT_TRUE(MGraph_frist_vertex(dnMGraph, 'B') == 2);
		EXPECT_TRUE(MGraph_next_vertex(dnMGraph, 'A', 'B') == 5);

		puts("深度遍历图:预期为ABCDFE");
		MGraph_DFS(dnMGraph);
		puts("广度遍历图");
		MGraph_HFS(dnMGraph);

		test_dn_mgraph_add_and_del();
	}
	else {
		LOG("IO ERR");
		EXPECT_TRUE(0);
	}

	puts("(3) 测试无向图");
	FILE * udg_fp = fopen("test_data/UDG.txt", "r");
	if (udg_fp) {
		udgMGraph = MGraph_create(udg_fp);
		EXPECT_TRUE(udgMGraph != NULL);
		fclose(udg_fp);
		MGraph_print(udgMGraph);

		EXPECT_TRUE(MGraph_locate(udgMGraph, 'C') == 2);
		EXPECT_TRUE(MGraph_get(udgMGraph, 2) == 'C');
		EXPECT_TRUE(MGraph_frist_vertex(udgMGraph, 'B') == 0);
		EXPECT_TRUE(MGraph_next_vertex(udgMGraph, 'A', 'B') == 3);

		puts("深度遍历图:预期为ABECD");
		MGraph_DFS(udgMGraph);
		puts("广度遍历图");
		MGraph_HFS(udgMGraph);

		test_udg_mgraph_add_and_del();
	}
	else {
		LOG("IO ERR");
		EXPECT_TRUE(0);
	}

	puts("(4) 测试无向网");
	FILE * udn_fg = fopen("test_data/UDN.txt", "r");
	if (udn_fg) {
		udnMGraph = MGraph_create(udn_fg);
		EXPECT_TRUE(udnMGraph != NULL);
		fclose(udn_fg);
		MGraph_print(udnMGraph);

		EXPECT_TRUE(MGraph_locate(udnMGraph, 'C') == 2);
		EXPECT_TRUE(MGraph_get(udnMGraph, 2) == 'C');
		EXPECT_TRUE(MGraph_frist_vertex(udnMGraph, 'B') == 0);
		EXPECT_TRUE(MGraph_next_vertex(udnMGraph, 'A', 'B') == 2);

		puts("深度遍历图:ABCDE");
		MGraph_DFS(udnMGraph);
		puts("广度遍历图");
		MGraph_HFS(udnMGraph);

		test_udn_mgraph_add_and_del();
	}
	else {
		LOG("IO ERR");
		EXPECT_TRUE(0);
	}
}

void test_udn_mgraph_add_and_del()
{
	puts("--> 增删改测试");
	puts("对顶点 A 赋值 X");
	MGraph_set(udnMGraph, 'A', 'X');
	EXPECT_EQ_INT(0, MGraph_locate(udnMGraph, 'X'));
	EXPECT_TRUE(MGraph_get(udnMGraph, 0) == 'X');
	//MGraph_print(udnMGraph);

	puts("插入顶点 H 后");
	EXPECT_EQ_INT(OK, MGraph_add_vertex(udnMGraph, 'H'));
	EXPECT_EQ_INT(6, udnMGraph->numVertexes);
	EXPECT_EQ_INT(6, udnMGraph->numEdges);
	EXPECT_EQ_INT(5, MGraph_locate(udnMGraph, 'H'));
	EXPECT_TRUE(MGraph_get(udnMGraph, 5) == 'H');
	//MGraph_print(udnMGraph);

	puts("依次插入边H-X-1,H-C-1,D-H-1,H-D-1");
	EXPECT_EQ_INT(OK, MGraph_add_arc(udnMGraph, 'H', 'X', 1));
	EXPECT_EQ_INT(OK, MGraph_add_arc(udnMGraph, 'H', 'C', 1));
	EXPECT_EQ_INT(OK, MGraph_add_arc(udnMGraph, 'D', 'H', 1));
	EXPECT_EQ_INT(OK, MGraph_add_arc(udnMGraph, 'H', 'D', 1));

	EXPECT_TRUE(MGraph_arc_exist(udnMGraph, 'H', 'X'));
	EXPECT_TRUE(MGraph_arc_exist(udnMGraph, 'H', 'C'));
	EXPECT_TRUE(MGraph_arc_exist(udnMGraph, 'D', 'H'));
	EXPECT_TRUE(MGraph_arc_exist(udnMGraph, 'H', 'D'));

	EXPECT_EQ_INT(1, MGraph_arc_weight(udnMGraph, 'H', 'X'));
	EXPECT_EQ_INT(1, MGraph_arc_weight(udnMGraph, 'H', 'C'));
	EXPECT_EQ_INT(1, MGraph_arc_weight(udnMGraph, 'D', 'H'));
	EXPECT_EQ_INT(1, MGraph_arc_weight(udnMGraph, 'H', 'D'));

	EXPECT_EQ_INT(6, udnMGraph->numVertexes);
	EXPECT_EQ_INT(9, udnMGraph->numEdges);
	//MGraph_print(udnMGraph);

	puts("删除边 H-X");
	EXPECT_EQ_INT(OK, MGraph_del_arc(udnMGraph, 'H', 'X'));
	EXPECT_EQ_INT(8, udnMGraph->numEdges);
	EXPECT_FALSE(MGraph_arc_exist(udnMGraph, 'H', 'X'));
	//MGraph_print(udnMGraph);

	puts("删除顶点 B");
	EXPECT_EQ_INT(OK, MGraph_del_vertex(udnMGraph, 'B'));
	EXPECT_EQ_INT(6, udnMGraph->numEdges);
	EXPECT_EQ_INT(5, udnMGraph->numVertexes);
	EXPECT_TRUE(MGraph_locate(udnMGraph, 'B') < 0);
	//MGraph_print(udnMGraph);

	puts("清除图");
	MGraph_clear(udnMGraph);
	EXPECT_EQ_INT(0, udnMGraph->numEdges);
	EXPECT_EQ_INT(0, udnMGraph->numVertexes);

	puts("销毁图");
	MGraph_destroy(&udnMGraph);
	EXPECT_TRUE(udnMGraph == NULL);
}

void test_udg_mgraph_add_and_del()
{
	puts("--> 增删改测试");
	puts("对顶点 A 赋值 X");
	MGraph_set(udgMGraph, 'A', 'X');
	EXPECT_EQ_INT(0, MGraph_locate(udgMGraph, 'X'));
	EXPECT_TRUE(MGraph_get(udgMGraph, 0) == 'X');
	//MGraph_print(udgMGraph);

	puts("插入顶点 H 后");
	EXPECT_EQ_INT(OK, MGraph_add_vertex(udgMGraph, 'H'));
	EXPECT_EQ_INT(6, udgMGraph->numVertexes);
	EXPECT_EQ_INT(6, udgMGraph->numEdges);
	EXPECT_EQ_INT(5, MGraph_locate(udgMGraph, 'H'));
	EXPECT_TRUE(MGraph_get(udgMGraph, 5) == 'H');
	MGraph_print(udgMGraph);

	puts("依次插入边H-X-1,H-C-1,D-H-1,H-D-1");
	EXPECT_EQ_INT(OK, MGraph_add_arc(udgMGraph, 'H', 'X', 1));
	EXPECT_EQ_INT(OK, MGraph_add_arc(udgMGraph, 'H', 'C', 1));
	EXPECT_EQ_INT(OK, MGraph_add_arc(udgMGraph, 'D', 'H', 1));
	EXPECT_EQ_INT(OK, MGraph_add_arc(udgMGraph, 'H', 'D', 1));

	EXPECT_TRUE(MGraph_arc_exist(udgMGraph, 'H', 'X'));
	EXPECT_TRUE(MGraph_arc_exist(udgMGraph, 'H', 'C'));
	EXPECT_TRUE(MGraph_arc_exist(udgMGraph, 'D', 'H'));
	EXPECT_TRUE(MGraph_arc_exist(udgMGraph, 'H', 'D'));

	EXPECT_EQ_INT(1, MGraph_arc_weight(udgMGraph, 'H', 'X'));
	EXPECT_EQ_INT(1, MGraph_arc_weight(udgMGraph, 'H', 'C'));
	EXPECT_EQ_INT(1, MGraph_arc_weight(udgMGraph, 'D', 'H'));
	EXPECT_EQ_INT(1, MGraph_arc_weight(udgMGraph, 'H', 'D'));

	EXPECT_EQ_INT(6, udgMGraph->numVertexes);
	EXPECT_EQ_INT(9, udgMGraph->numEdges);
	//MGraph_print(udgMGraph);

	puts("删除边 H-X");
	EXPECT_EQ_INT(OK, MGraph_del_arc(udgMGraph, 'H', 'X'));
	EXPECT_EQ_INT(8, udgMGraph->numEdges);
	EXPECT_FALSE(MGraph_arc_exist(udgMGraph, 'H', 'X'));
	//MGraph_print(udgMGraph);

	puts("删除顶点 B");
	EXPECT_EQ_INT(OK, MGraph_del_vertex(udgMGraph, 'B'));
	EXPECT_EQ_INT(6, udgMGraph->numEdges);
	EXPECT_EQ_INT(5, udgMGraph->numVertexes);
	EXPECT_TRUE(MGraph_locate(udgMGraph, 'B') < 0);
	//MGraph_print(udgMGraph);

	puts("清除图");
	MGraph_clear(udgMGraph);
	EXPECT_EQ_INT(0, udgMGraph->numEdges);
	EXPECT_EQ_INT(0, udgMGraph->numVertexes);

	puts("销毁图");
	MGraph_destroy(&udgMGraph);
	EXPECT_TRUE(udgMGraph == NULL);
}

void test_dn_mgraph_add_and_del()
{
	puts("--> 增删改测试");
}

void test_dg_mgraph_add_and_del()
{
	puts("--> 增删改测试");
	puts("对顶点 A 赋值 X之后，DG图=");
	MGraph_set(dgMGraph, 'A', 'X');
	EXPECT_EQ_INT(0, MGraph_locate(dgMGraph, 'X'));
	EXPECT_TRUE(MGraph_get(dgMGraph, 0) == 'X');
	//MGraph_print(dgMGraph);

	puts("插入顶点 H 后， DG图=");
	EXPECT_EQ_INT(OK, MGraph_add_vertex(dgMGraph, 'H'));
	EXPECT_EQ_INT(5, dgMGraph->numVertexes);
	EXPECT_EQ_INT(4, dgMGraph->numEdges);
	EXPECT_EQ_INT(4, MGraph_locate(dgMGraph, 'H'));
	EXPECT_TRUE(MGraph_get(dgMGraph, 4) == 'H');
	//MGraph_print(dgMGraph);

	puts("依次插入边H-X-1,H-C-1,D-H-1");
	EXPECT_EQ_INT(OK, MGraph_add_arc(dgMGraph, 'H', 'X', 1));
	EXPECT_EQ_INT(OK, MGraph_add_arc(dgMGraph, 'H', 'C', 1));
	EXPECT_EQ_INT(OK, MGraph_add_arc(dgMGraph, 'D', 'H', 1));

	EXPECT_TRUE(MGraph_arc_exist(dgMGraph, 'H', 'X'));
	EXPECT_TRUE(MGraph_arc_exist(dgMGraph, 'H', 'C'));
	EXPECT_TRUE(MGraph_arc_exist(dgMGraph, 'D', 'H'));

	EXPECT_EQ_INT(1, MGraph_arc_weight(dgMGraph, 'H', 'X'));
	EXPECT_EQ_INT(1, MGraph_arc_weight(dgMGraph, 'H', 'C'));
	EXPECT_EQ_INT(1, MGraph_arc_weight(dgMGraph, 'D', 'H'));

	EXPECT_EQ_INT(5, dgMGraph->numVertexes);
	EXPECT_EQ_INT(7, dgMGraph->numEdges);
	//MGraph_print(dgMGraph);

	puts("删除边 H-X");
	EXPECT_EQ_INT(OK, MGraph_del_arc(dgMGraph, 'H', 'X'));
	EXPECT_EQ_INT(6, dgMGraph->numEdges);
	EXPECT_FALSE(MGraph_arc_exist(dgMGraph, 'H', 'X'));
	//MGraph_print(dgMGraph);

	puts("删除顶点 B");
	EXPECT_EQ_INT(OK, MGraph_del_vertex(dgMGraph, 'B'));
	EXPECT_EQ_INT(4, dgMGraph->numEdges);
	EXPECT_EQ_INT(4, dgMGraph->numVertexes);
	EXPECT_TRUE(MGraph_locate(dgMGraph, 'B') < 0);
	//MGraph_print(dgMGraph);

	puts("清除图");
	MGraph_clear(dgMGraph);
	EXPECT_EQ_INT(0, dgMGraph->numEdges);
	EXPECT_EQ_INT(0, dgMGraph->numVertexes);

	puts("销毁图");
	MGraph_destroy(&dgMGraph);
	EXPECT_TRUE(dgMGraph == NULL);
}

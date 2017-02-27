void initValues() {
	int tempA[98] = {57,275,63,219,84,169,117,121,164,89,216,65,271,59,328,63,381,88,426,125,463,168,480,221,489,276,480,330,458,384,425,425,381,458,328,484,273,489,214,485,161,461,116,428,83,382,63,333,116,223,146,278,114,329,147,167,209,167,241,217,206,272,240,112,397,164,333,166,302,115,429,225,397,277,336,276,304,223,430,329,305,439,334,382,398,386,241,437,214,382,240,333,302,328,145,382,271,275},
	tempB[126] = {0,1,23,0,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,17,17,18,18,19,19,20,20,21,21,22,22,23,2,24,24,25,25,26,26,22,24,27,27,28,28,29,29,30,30,25,2,27,31,6,31,28,6,34,34,33,33,32,32,10,32,35,35,36,36,37,37,38,38,33,10,35,36,39,39,14,42,14,42,41,40,41,40,18,41,46,46,45,45,44,44,43,43,40,18,43,44,47,47,22,25,44,28,33,36,41},
	tempC[63] = {82,97,67,52,37,22,7,-7,-22,-37,-52,-67,-82,-97,-112,-127,-142,-157,-172,172,157,142,127,112,-60,-60,-120,-120,60,0,-60,-120,180,0,60,-120,-60,-60,0,0,-60,-120,180,120,60,-120,-60,-60,0,180,60,-120,120,180,-120,-60,0,120,180,180,-60,0,-120},
	tempD[63] = {20,21,19,21,20,20,20,20,21,21,20,20,20,19,21,18,20,21,20,21,21,20,20,18,22,21,21,22,21,21,21,23,21,23,22,23,23,21,23,24,24,22,22,22,23,24,22,22,21,23,23,21,22,22,20,22,23,22,25,22,45,45,44},
	i;
	for (i = 0; i < 49; i++) {
		nodes[i].x = tempA[2*i];
		nodes[i].y = tempA[2*i+1];
		nodes[i].edgeCount = 0;
	}
	for (i = 0; i < 63; i++) {
		edgeList[i].obstacle = 0;
		edgeList[i].start = tempB[2*i];
		edgeList[i].end = tempB[2*i+1];
		edgeList[i].startCompass = tempC[i];
		edgeList[i].distance = tempD[i];
		nodes[edgeList[i].start].edgeIndices[(nodes[edgeList[i].start].edgeCount)++] = i;
		nodes[edgeList[i].end].edgeIndices[(nodes[edgeList[i].end].edgeCount)++] = i;
		if ((edgeList[i].startCompass) % 10 == 0) {
			edgeList[i].leftSpeedRatio = 3;
			edgeList[i].rightSpeedRatio = 3;
		} else {
			edgeList[i].leftSpeedRatio = 3;
			edgeList[i].rightSpeedRatio = 2;
		}
	}
	pathLenA = pathLenB = 0;
}
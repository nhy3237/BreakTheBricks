unsigned _stdcall Timer();

void draw_bricks();
void HitPoint(int HP);
void level1_play(int player, int HP);

void print_rubble(void); // 화면에 장애물을 뿌려준다
void check_hit(void); // 장애물과 캐릭터 충돌 체크
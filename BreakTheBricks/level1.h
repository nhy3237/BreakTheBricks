unsigned _stdcall Timer();

void draw_bricks();
void HitPoint(int HP);
void level1_play(int player);

unsigned _stdcall print_rubble(void); // 화면에 장애물을 뿌려준다
void check_hit(int po_x, int po_y); // 장애물과 캐릭터 충돌 체크
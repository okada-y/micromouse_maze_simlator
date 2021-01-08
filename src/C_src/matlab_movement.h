#ifndef MATLAB_MOVEMENT
#define MATLAB_MOVEMENT

//�O�i
void m_move_front(unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);

//�O�i_�����O
void m_move_front_long(unsigned char straight_count,unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);

//�E��
void m_move_right(unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);

//����
void m_move_left(unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);

//�o�b�N
void m_move_back(unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);

//�X�^�[�g������
void m_start_movement(unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);

//�S�[�����̓���i��~�����j
void m_goal_movement(unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);

//�G���[���̓���
void m_error_movement(unsigned char error_flg);

//�EV90�x�^�[��
void m_turn_V90_r(unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);
//��V90�x�^�[��
void m_turn_V90_l(unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);
//�E90�x�^�[��
void m_turn_90_r(unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);
//��90�x�^�[��
void m_turn_90_l(unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);
//�E180�x�^�[��
void m_turn_180_r(unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);
//��180�x�^�[��
void m_turn_180_l(unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);
//�E135�x�^�[��
void m_turn_135_r(unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);
//��135�x�^�[��
void m_turn_135_l(unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);
//�E45�x�^�[��
void m_turn_45_r(unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);
//��45�x�^�[��
void m_turn_45_l(unsigned char start_flg,unsigned char wall_flg,unsigned char move_dir_property);

#endif
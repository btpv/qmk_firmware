#pragma once
#define SEQ_1   1
#define SEQ_2   SEQ_1, 2
#define SEQ_3   SEQ_2, 3
#define SEQ_4   SEQ_3, 4
#define SEQ_5   SEQ_4, 5
#define SEQ_6   SEQ_5, 6
#define SEQ_7   SEQ_6, 7
#define SEQ_8   SEQ_7, 8
#define SEQ_9   SEQ_8, 9
#define SEQ_10  SEQ_9, 10

#define SEQ_11  SEQ_10, 11
#define SEQ_12  SEQ_11, 12
#define SEQ_13  SEQ_12, 13
#define SEQ_14  SEQ_13, 14
#define SEQ_15  SEQ_14, 15
#define SEQ_16  SEQ_15, 16
#define SEQ_17  SEQ_16, 17
#define SEQ_18  SEQ_17, 18
#define SEQ_19  SEQ_18, 19
#define SEQ_20  SEQ_19, 20

#define SEQ_21  SEQ_20, 21
#define SEQ_22  SEQ_21, 22
#define SEQ_23  SEQ_22, 23
#define SEQ_24  SEQ_23, 24
#define SEQ_25  SEQ_24, 25
#define SEQ_26  SEQ_25, 26
#define SEQ_27  SEQ_26, 27
#define SEQ_28  SEQ_27, 28
#define SEQ_29  SEQ_28, 29
#define SEQ_30  SEQ_29, 30

#define SEQ_31  SEQ_30, 31
#define SEQ_32  SEQ_31, 32
#define SEQ_33  SEQ_32, 33
#define SEQ_34  SEQ_33, 34
#define SEQ_35  SEQ_34, 35
#define SEQ_36  SEQ_35, 36
#define SEQ_37  SEQ_36, 37
#define SEQ_38  SEQ_37, 38
#define SEQ_39  SEQ_38, 39
#define SEQ_40  SEQ_39, 40

#define SEQ_41  SEQ_40, 41
#define SEQ_42  SEQ_41, 42
#define SEQ_43  SEQ_42, 43
#define SEQ_44  SEQ_43, 44
#define SEQ_45  SEQ_44, 45
#define SEQ_46  SEQ_45, 46
#define SEQ_47  SEQ_46, 47
#define SEQ_48  SEQ_47, 48
#define SEQ_49  SEQ_48, 49
#define SEQ_50  SEQ_49, 50

#define SEQ_51  SEQ_50, 51
#define SEQ_52  SEQ_51, 52
#define SEQ_53  SEQ_52, 53
#define SEQ_54  SEQ_53, 54
#define SEQ_55  SEQ_54, 55
#define SEQ_56  SEQ_55, 56
#define SEQ_57  SEQ_56, 57
#define SEQ_58  SEQ_57, 58
#define SEQ_59  SEQ_58, 59
#define SEQ_60  SEQ_59, 60

#define SEQ_61  SEQ_60, 61
#define SEQ_62  SEQ_61, 62
#define SEQ_63  SEQ_62, 63
#define SEQ_64  SEQ_63, 64
#define SEQ_65  SEQ_64, 65
#define SEQ_66  SEQ_65, 66
#define SEQ_67  SEQ_66, 67
#define SEQ_68  SEQ_67, 68
#define SEQ_69  SEQ_68, 69
#define SEQ_70  SEQ_69, 70

#define SEQ_71  SEQ_70, 71
#define SEQ_72  SEQ_71, 72
#define SEQ_73  SEQ_72, 73
#define SEQ_74  SEQ_73, 74
#define SEQ_75  SEQ_74, 75
#define SEQ_76  SEQ_75, 76
#define SEQ_77  SEQ_76, 77
#define SEQ_78  SEQ_77, 78
#define SEQ_79  SEQ_78, 79
#define SEQ_80  SEQ_79, 80

#define SEQ_81  SEQ_80, 81
#define SEQ_82  SEQ_81, 82
#define SEQ_83  SEQ_82, 83
#define SEQ_84  SEQ_83, 84
#define SEQ_85  SEQ_84, 85
#define SEQ_86  SEQ_85, 86
#define SEQ_87  SEQ_86, 87
#define SEQ_88  SEQ_87, 88
#define SEQ_89  SEQ_88, 89
#define SEQ_90  SEQ_89, 90

#define SEQ_91  SEQ_90, 91
#define SEQ_92  SEQ_91, 92
#define SEQ_93  SEQ_92, 93
#define SEQ_94  SEQ_93, 94
#define SEQ_95  SEQ_94, 95
#define SEQ_96  SEQ_95, 96
#define SEQ_97  SEQ_96, 97
#define SEQ_98  SEQ_97, 98
#define SEQ_99  SEQ_98, 99
#define SEQ_100 SEQ_99, 100

#define SEQ_101 SEQ_100, 101
#define SEQ_102 SEQ_101, 102
#define SEQ_103 SEQ_102, 103
#define SEQ_104 SEQ_103, 104
#define SEQ_105 SEQ_104, 105
#define SEQ_106 SEQ_105, 106
#define SEQ_107 SEQ_106, 107
#define SEQ_108 SEQ_107, 108
#define SEQ_109 SEQ_108, 109
#define SEQ_110 SEQ_109, 110

#define SEQ_111 SEQ_110, 111
#define SEQ_112 SEQ_111, 112
#define SEQ_113 SEQ_112, 113
#define SEQ_114 SEQ_113, 114
#define SEQ_115 SEQ_114, 115
#define SEQ_116 SEQ_115, 116
#define SEQ_117 SEQ_116, 117
#define SEQ_118 SEQ_117, 118
#define SEQ_119 SEQ_118, 119
#define SEQ_120 SEQ_119, 120

#define SEQ_121 SEQ_120, 121
#define SEQ_122 SEQ_121, 122
#define SEQ_123 SEQ_122, 123
#define SEQ_124 SEQ_123, 124
#define SEQ_125 SEQ_124, 125
#define SEQ_126 SEQ_125, 126
#define SEQ_127 SEQ_126, 127
#define SEQ_128 SEQ_127, 128

// selector
#define CAT(a,b) a##b
#define SEQ(n) CAT(SEQ_, n)
#define SEQUENCE SEQ(24)

// #define getRgbLayoutIndex(row,col) ((uint8_t[MATRIX_ROWS][MATRIX_COLS])rgbLayoutMap)[row][col] - 1

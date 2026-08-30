@ Generated with Luvdis v0.8.0
.syntax unified
.text
@ Begin embedded Luvdis macros
	.macro arm_func_start name
	.align 2, 0
	.global \name
	.arm
	.type \name, %function
	.endm

	.macro arm_func_end name
	.size \name, .-\name
	.endm

	.macro thumb_func_start name
	.align 2, 0
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro non_word_aligned_thumb_func_start name
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro thumb_func_end name
	.size \name, .-\name
	.endm
@ End embedded Luvdis macros

	thumb_func_start mode_mapinspect_0
mode_mapinspect_0: @ 08108CE8
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08108DB4 @ =0x02035E28
	movs r0, #0xBD
	lsls r0, r0, #0x02
	bl func_08000918
	str r0, [r4, #0x00]
	bl func_08001F98
	movs r0, #0x00
	movs r1, #0x10
	bl func_08006120
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x1C
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x1D
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x02
	movs r1, #0x02
	movs r2, #0x1E
	movs r3, #0x0F
	bl func_08005074
	movs r0, #0x03
	movs r1, #0x00
	movs r2, #0x1F
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x00
	movs r1, #0x03
	bl func_080055C8
	movs r0, #0x01
	movs r1, #0x02
	bl func_080055C8
	movs r0, #0x02
	movs r1, #0x01
	bl func_080055C8
	movs r0, #0x03
	movs r1, #0x00
	bl func_080055C8
	bl func_08107B84
	ldr r0, _08108DB8 @ =0x02035FCA
	movs r2, #0x00
	strh r2, [r0, #0x00]
	ldr r1, _08108DBC @ =0x02035FCC
	movs r0, #0x10
	strh r0, [r1, #0x00]
	ldr r1, _08108DC0 @ =0x02035FD0
	ldr r0, _08108DC4 @ =0xFFFFF800
	str r0, [r1, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x08
	str r0, [r1, #0x04]
	ldr r1, _08108DC8 @ =0x02035FD8
	ldr r0, _08108DCC @ =0xFFFF8000
	str r0, [r1, #0x00]
	ldr r1, _08108DD0 @ =0x02035E2E
	movs r0, #0x04
	strh r0, [r1, #0x00]
	ldr r0, _08108DD4 @ =0x02035E98
	strh r2, [r0, #0x00]
	ldr r0, _08108DD8 @ =0x02035E9A
	strh r2, [r0, #0x00]
	ldr r0, _08108DDC @ =0x02035E9C
	strh r2, [r0, #0x00]
	ldr r0, _08108DE0 @ =0x02035E48
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x00
	ble _08108DF4
	ldr r1, _08108DE4 @ =0x02035FDC
	movs r2, #0x00
	ldr r0, _08108DE8 @ =0xFFFFFE00
	str r0, [r1, #0x00]
	ldr r1, _08108DEC @ =0x02035FE0
	movs r0, #0x80
	lsls r0, r0, #0x05
	str r0, [r1, #0x00]
	ldr r0, _08108DF0 @ =0x02035E2C
	strh r2, [r0, #0x00]
	b _08108E14
	.byte 0x00, 0x00
_08108DB4: .4byte 0x02035E28
_08108DB8: .4byte 0x02035FCA
_08108DBC: .4byte 0x02035FCC
_08108DC0: .4byte 0x02035FD0
_08108DC4: .4byte 0xFFFFF800
_08108DC8: .4byte 0x02035FD8
_08108DCC: .4byte 0xFFFF8000
_08108DD0: .4byte 0x02035E2E
_08108DD4: .4byte 0x02035E98
_08108DD8: .4byte 0x02035E9A
_08108DDC: .4byte 0x02035E9C
_08108DE0: .4byte 0x02035E48
_08108DE4: .4byte 0x02035FDC
_08108DE8: .4byte 0xFFFFFE00
_08108DEC: .4byte 0x02035FE0
_08108DF0: .4byte 0x02035E2C
_08108DF4:
	ldr r2, _08108EF4 @ =0x02035FDC
	ldr r0, _08108EF8 @ =0x09EF9618
	movs r3, #0x24
	ldsh r1, [r0, r3]
	lsls r0, r1, #0x03
	subs r0, r0, r1
	lsls r0, r0, #0x09
	ldr r1, _08108EFC @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r2, #0x00]
	ldr r1, _08108F00 @ =0x02035FE0
	movs r0, #0x00
	str r0, [r1, #0x00]
	ldr r1, _08108F04 @ =0x02035E2C
	movs r0, #0x01
	strh r0, [r1, #0x00]
_08108E14:
	movs r1, #0x00
	ldr r3, _08108F08 @ =0x02035ED0
	mov r10, r3
	ldr r0, _08108F0C @ =0x02035F00
	mov r9, r0
	ldr r3, _08108F10 @ =0x02035EA0
	mov r8, r3
	movs r5, #0x00
	ldr r0, _08108F14 @ =0x02035F30
	mov r12, r0
_08108E28:
	movs r3, #0x00
	lsls r7, r1, #0x10
	asrs r1, r7, #0x10
	lsls r0, r1, #0x01
	adds r4, r0, r1
	lsls r6, r4, #0x02
_08108E34:
	lsls r2, r3, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #0x02
	adds r0, r0, r6
	mov r3, r8
	adds r1, r0, r3
	str r5, [r1, #0x00]
	mov r3, r10
	adds r1, r0, r3
	str r5, [r1, #0x00]
	add r0, r9
	str r5, [r0, #0x00]
	adds r0, r2, r4
	add r0, r12
	strb r5, [r0, #0x00]
	adds r2, #0x01
	lsls r2, r2, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0x02
	ble _08108E34
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r7, r1
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	ble _08108E28
	movs r0, #0x00
	ldr r3, _08108F18 @ =0x02035F3C
	str r0, [r3, #0x00]
	ldr r1, _08108F1C @ =0x02035F40
	str r0, [r1, #0x00]
	ldr r3, _08108F20 @ =0x02035F44
	str r0, [r3, #0x00]
	ldr r1, _08108F24 @ =0x02035F48
	str r0, [r1, #0x00]
	ldr r3, _08108F28 @ =0x02035F4C
	str r0, [r3, #0x00]
	ldr r1, _08108F2C @ =0x02035F50
	str r0, [r1, #0x00]
	ldr r3, _08108F30 @ =0x02035F90
	strb r0, [r3, #0x00]
	ldr r1, _08108F34 @ =0x02035E74
	str r0, [r1, #0x00]
	ldr r3, _08108F38 @ =0x02035FC4
	strh r0, [r3, #0x00]
	ldr r1, _08108F3C @ =0x02035FC6
	strh r0, [r1, #0x00]
	movs r2, #0xB0
	lsls r2, r2, #0x01
	ldr r1, _08108F40 @ =0x09A3D0DC
	bl func_080050DC
	ldr r1, _08108F44 @ =0x09A03CFC
	movs r2, #0xA6
	lsls r2, r2, #0x06
	movs r0, #0x00
	bl func_080050B8
	ldr r1, _08108F48 @ =0x09611AB8
	movs r0, #0x02
	movs r2, #0x20
	bl func_080050DC
	ldr r1, _08108F4C @ =0x099597E4
	movs r2, #0xA0
	lsls r2, r2, #0x01
	movs r0, #0x02
	bl func_080050B8
	ldr r1, _08108F50 @ =0x09985F44
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x02
	bl func_0800510C
	ldr r1, _08108F54 @ =0x09A3439C
	movs r4, #0xA0
	lsls r4, r4, #0x03
	movs r0, #0x00
	adds r2, r4, #0x0
	bl func_0800510C
	bl func_0810718C
	ldrh r0, [r0, #0x04]
	cmp r0, #0x03
	bne _08108F5C
	ldr r1, _08108F58 @ =0x09A3551C
	movs r0, #0x01
	adds r2, r4, #0x0
	bl func_0800510C
	b _08108F66
	.byte 0x00, 0x00
_08108EF4: .4byte 0x02035FDC
_08108EF8: .4byte 0x09EF9618
_08108EFC: .4byte 0xFFFFFF00
_08108F00: .4byte 0x02035FE0
_08108F04: .4byte 0x02035E2C
_08108F08: .4byte 0x02035ED0
_08108F0C: .4byte 0x02035F00
_08108F10: .4byte 0x02035EA0
_08108F14: .4byte 0x02035F30
_08108F18: .4byte 0x02035F3C
_08108F1C: .4byte 0x02035F40
_08108F20: .4byte 0x02035F44
_08108F24: .4byte 0x02035F48
_08108F28: .4byte 0x02035F4C
_08108F2C: .4byte 0x02035F50
_08108F30: .4byte 0x02035F90
_08108F34: .4byte 0x02035E74
_08108F38: .4byte 0x02035FC4
_08108F3C: .4byte 0x02035FC6
_08108F40: .4byte 0x09A3D0DC
_08108F44: .4byte 0x09A03CFC
_08108F48: .4byte 0x09611AB8
_08108F4C: .4byte 0x099597E4
_08108F50: .4byte 0x09985F44
_08108F54: .4byte 0x09A3439C
_08108F58: .4byte 0x09A3551C
_08108F5C:
	ldr r1, _08109120 @ =0x09A3501C
	movs r0, #0x01
	adds r2, r4, #0x0
	bl func_0800510C
_08108F66:
	ldr r0, _08109124 @ =0x02035E2E
	movs r3, #0x00
	ldsh r0, [r0, r3]
	bl func_081078F0
	bl func_081075FC
	bl func_0810764C
	bl func_081076D4
	ldr r5, _08109128 @ =0x09A3D2DC
	adds r0, r5, #0x0
	movs r1, #0x20
	bl func_08002A14
	ldr r1, _0810912C @ =0x02035E4C
	str r0, [r1, #0x00]
	ldr r0, _08109130 @ =0x0999DAEC
	movs r1, #0xAC
	lsls r1, r1, #0x04
	bl func_080026A4
	ldr r1, _08109134 @ =0x02035E50
	str r0, [r1, #0x00]
	ldr r4, _08109138 @ =0x02035E58
	ldr r1, _0810913C @ =0x09EF981C
	ldr r2, _08109140 @ =0x09EF97EC
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	ldr r0, _08109144 @ =0x0999E69E
	movs r1, #0xD6
	lsls r1, r1, #0x04
	bl func_080026A4
	ldr r1, _08109148 @ =0x02035E78
	str r0, [r1, #0x00]
	ldr r4, _0810914C @ =0x02035E80
	ldr r1, _08109150 @ =0x09EF9858
	ldr r2, _08109154 @ =0x09EF9830
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	adds r0, r5, #0x0
	movs r1, #0x20
	bl func_08002A14
	ldr r1, _08109158 @ =0x02035E70
	str r0, [r1, #0x00]
	ldr r0, _0810915C @ =0x0908B1B4
	movs r1, #0x9A
	lsls r1, r1, #0x04
	bl func_080026A4
	ldr r1, _08109160 @ =0x02035F54
	str r0, [r1, #0x00]
	ldr r4, _08109164 @ =0x02035F58
	ldr r1, _08109168 @ =0x09EEA164
	ldr r2, _0810916C @ =0x09EEA148
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	ldr r0, _08109170 @ =0x0908C3CE
	movs r1, #0x98
	lsls r1, r1, #0x02
	bl func_080026A4
	ldr r1, _08109174 @ =0x02035F70
	str r0, [r1, #0x00]
	ldr r4, _08109178 @ =0x02035F78
	ldr r1, _0810917C @ =0x09EEA198
	ldr r2, _08109180 @ =0x09EEA180
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	ldr r4, _08109184 @ =0x02035F94
	movs r0, #0x90
	lsls r0, r0, #0x01
	bl func_08000918
	str r0, [r4, #0x00]
	movs r1, #0x24
	bl func_08065ACC
	ldr r4, _08109188 @ =0x02035F9C
	movs r0, #0xB4
	lsls r0, r0, #0x02
	bl func_08000918
	str r0, [r4, #0x00]
	movs r1, #0x5A
	bl func_08065ACC
	ldr r6, _0810918C @ =0x08159FBC
	adds r0, r6, #0x0
	bl func_08065B54
	ldr r4, _08109190 @ =0x02035FAA
	strh r0, [r4, #0x00]
	ldr r5, _08109194 @ =0x02035FA4
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x03
	bl func_08000918
	str r0, [r5, #0x00]
	ldrh r1, [r4, #0x00]
	bl func_08065ACC
	ldr r4, _08109198 @ =0x02035FA8
	ldr r1, [r5, #0x00]
	adds r0, r6, #0x0
	bl func_08065B6C
	strb r0, [r4, #0x00]
	ldr r6, _0810919C @ =0x08159E10
	adds r0, r6, #0x0
	bl func_08065B54
	ldr r4, _081091A0 @ =0x02035FB2
	strh r0, [r4, #0x00]
	ldr r5, _081091A4 @ =0x02035FAC
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x03
	bl func_08000918
	str r0, [r5, #0x00]
	ldrh r1, [r4, #0x00]
	bl func_08065ACC
	ldr r4, _081091A8 @ =0x02035FB0
	ldr r1, [r5, #0x00]
	adds r0, r6, #0x0
	bl func_08065B6C
	strb r0, [r4, #0x00]
	ldr r6, _081091AC @ =0x08159E18
	adds r0, r6, #0x0
	bl func_08065B54
	ldr r4, _081091B0 @ =0x02035FBA
	strh r0, [r4, #0x00]
	ldr r5, _081091B4 @ =0x02035FB4
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x03
	bl func_08000918
	str r0, [r5, #0x00]
	ldrh r1, [r4, #0x00]
	bl func_08065ACC
	ldr r4, _081091B8 @ =0x02035FB8
	ldr r1, [r5, #0x00]
	adds r0, r6, #0x0
	bl func_08065B6C
	strb r0, [r4, #0x00]
	ldr r6, _081091BC @ =0x0815C136
	adds r0, r6, #0x0
	bl func_08065B54
	ldr r4, _081091C0 @ =0x02035FC2
	strh r0, [r4, #0x00]
	ldrh r0, [r4, #0x00]
	lsls r0, r0, #0x03
	bl func_08000918
	ldr r5, _081091C4 @ =0x02035FBC
	str r0, [r5, #0x00]
	ldrh r1, [r4, #0x00]
	bl func_08065ACC
	ldr r1, [r5, #0x00]
	adds r0, r6, #0x0
	bl func_08065B6C
	ldr r1, _081091C8 @ =0x02035FC0
	strb r0, [r1, #0x00]
	bl func_08107280
	bl func_081073F0
	movs r0, #0x00
	bl func_08004FC8
	movs r0, #0x01
	bl func_08004FC8
	movs r0, #0x02
	bl func_0800501C
	movs r0, #0x03
	bl func_0800501C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08109120: .4byte 0x09A3501C
_08109124: .4byte 0x02035E2E
_08109128: .4byte 0x09A3D2DC
_0810912C: .4byte 0x02035E4C
_08109130: .4byte 0x0999DAEC
_08109134: .4byte 0x02035E50
_08109138: .4byte 0x02035E58
_0810913C: .4byte 0x09EF981C
_08109140: .4byte 0x09EF97EC
_08109144: .4byte 0x0999E69E
_08109148: .4byte 0x02035E78
_0810914C: .4byte 0x02035E80
_08109150: .4byte 0x09EF9858
_08109154: .4byte 0x09EF9830
_08109158: .4byte 0x02035E70
_0810915C: .4byte 0x0908B1B4
_08109160: .4byte 0x02035F54
_08109164: .4byte 0x02035F58
_08109168: .4byte 0x09EEA164
_0810916C: .4byte 0x09EEA148
_08109170: .4byte 0x0908C3CE
_08109174: .4byte 0x02035F70
_08109178: .4byte 0x02035F78
_0810917C: .4byte 0x09EEA198
_08109180: .4byte 0x09EEA180
_08109184: .4byte 0x02035F94
_08109188: .4byte 0x02035F9C
_0810918C: .4byte 0x08159FBC
_08109190: .4byte 0x02035FAA
_08109194: .4byte 0x02035FA4
_08109198: .4byte 0x02035FA8
_0810919C: .4byte 0x08159E10
_081091A0: .4byte 0x02035FB2
_081091A4: .4byte 0x02035FAC
_081091A8: .4byte 0x02035FB0
_081091AC: .4byte 0x08159E18
_081091B0: .4byte 0x02035FBA
_081091B4: .4byte 0x02035FB4
_081091B8: .4byte 0x02035FB8
_081091BC: .4byte 0x0815C136
_081091C0: .4byte 0x02035FC2
_081091C4: .4byte 0x02035FBC
_081091C8: .4byte 0x02035FC0
	thumb_func_start mode_mapinspect_1
mode_mapinspect_1: @ 081091CC
	push {r4, r5, lr}
	bl func_0801CC80
	ldr r0, _081091E8 @ =0x02035FCA
	movs r1, #0x00
	ldsh r0, [r0, r1]
	cmp r0, #0x05
	bls _081091DE
	b _0810936A
_081091DE:
	lsls r0, r0, #0x02
	ldr r1, _081091EC @ =0x081091F0
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
_081091E8: .4byte 0x02035FCA
_081091EC: .4byte 0x081091F0
	.byte 0x08, 0x92, 0x10, 0x08, 0x4C, 0x92, 0x10, 0x08, 0x8C, 0x92, 0x10, 0x08, 0xDA, 0x92, 0x10, 0x08
	.byte 0x10, 0x93, 0x10, 0x08, 0x58, 0x93, 0x10, 0x08, 0x0D, 0x4C, 0x0E, 0x4D, 0x2A, 0x88, 0x20, 0x1C
	.byte 0x00, 0x21, 0xFC, 0xF6, 0x73, 0xFB, 0x04, 0x34, 0x98, 0x21, 0x09, 0x02, 0x2A, 0x88, 0x20, 0x1C
	.byte 0xFC, 0xF6, 0x6C, 0xFB, 0x28, 0x88, 0x01, 0x38, 0x28, 0x80, 0x00, 0x04, 0x00, 0x28, 0x00, 0xDD
	.byte 0x9B, 0xE0, 0x10, 0x20, 0x28, 0x80, 0x04, 0x49, 0x01, 0x20, 0x08, 0x80, 0x95, 0xE0, 0x00, 0x00
	.byte 0xD0, 0x5F, 0x03, 0x02, 0xCC, 0x5F, 0x03, 0x02, 0xCA, 0x5F, 0x03, 0x02, 0x0B, 0x48, 0x0C, 0x4C
	.byte 0x22, 0x88, 0x00, 0x21, 0xFC, 0xF6, 0x52, 0xFB, 0x20, 0x88, 0x01, 0x38, 0x20, 0x80, 0x00, 0x04
	.byte 0x00, 0x28, 0x00, 0xDD, 0x81, 0xE0, 0x07, 0x49, 0xA0, 0x22, 0xD2, 0x00, 0x00, 0x20, 0xFB, 0xF6
	.byte 0x4D, 0xFF, 0x05, 0x49, 0x02, 0x20, 0x08, 0x80, 0x77, 0xE0, 0x00, 0x00, 0xD8, 0x5F, 0x03, 0x02
	.byte 0xCC, 0x5F, 0x03, 0x02, 0x9C, 0x48, 0xA3, 0x09, 0xCA, 0x5F, 0x03, 0x02, 0x04, 0x48, 0x00, 0x21
	.byte 0x40, 0x5E, 0x04, 0x28, 0x69, 0xD8, 0x80, 0x00, 0x02, 0x49, 0x40, 0x18, 0x00, 0x68, 0x87, 0x46
	.byte 0x2C, 0x5E, 0x03, 0x02, 0xA8, 0x92, 0x10, 0x08, 0xBC, 0x92, 0x10, 0x08, 0xC2, 0x92, 0x10, 0x08
	.byte 0xC8, 0x92, 0x10, 0x08, 0xCE, 0x92, 0x10, 0x08, 0xD4, 0x92, 0x10, 0x08, 0xFE, 0xF7, 0x42, 0xFD
	.byte 0x53, 0xE0, 0xFE, 0xF7, 0x95, 0xFE, 0x50, 0xE0, 0xFE, 0xF7, 0x9E, 0xFF, 0x4D, 0xE0, 0xFF, 0xF7
	.byte 0x8D, 0xF8, 0x4A, 0xE0, 0xFF, 0xF7, 0x88, 0xF9, 0x47, 0xE0, 0x09, 0x48, 0x09, 0x49, 0x0A, 0x4C
	.byte 0x22, 0x88, 0xFC, 0xF6, 0x0B, 0xFB, 0x20, 0x88, 0x01, 0x38, 0x20, 0x80, 0x00, 0x04, 0x00, 0x28
	.byte 0x3B, 0xDC, 0x10, 0x20, 0x20, 0x80, 0x05, 0x49, 0x04, 0x20, 0x08, 0x80, 0x35, 0xE0, 0x00, 0x00
	.byte 0xD8, 0x5F, 0x03, 0x02, 0x00, 0x80, 0xFF, 0xFF, 0xCC, 0x5F, 0x03, 0x02, 0xCA, 0x5F, 0x03, 0x02
	.byte 0x0D, 0x4C, 0x0E, 0x49, 0x0E, 0x4D, 0x2A, 0x88, 0x20, 0x1C, 0xFC, 0xF6, 0xEF, 0xFA, 0x04, 0x34
	.byte 0xA8, 0x21, 0x09, 0x02, 0x2A, 0x88, 0x20, 0x1C, 0xFC, 0xF6, 0xE8, 0xFA, 0x28, 0x88, 0x01, 0x38
	.byte 0x28, 0x80, 0x00, 0x04, 0x00, 0x28, 0x18, 0xDC, 0x00, 0x20, 0x10, 0x21, 0xFC, 0xF6, 0x22, 0xFF
	.byte 0x04, 0x49, 0x05, 0x20, 0x08, 0x80, 0x10, 0xE0, 0xD0, 0x5F, 0x03, 0x02, 0x00, 0xF8, 0xFF, 0xFF
	.byte 0xCC, 0x5F, 0x03, 0x02, 0xCA, 0x5F, 0x03, 0x02, 0xFC, 0xF6, 0xDC, 0xFF, 0x00, 0x06, 0x00, 0x28
	.byte 0x03, 0xD1, 0x04, 0x48, 0x00, 0x78, 0xD7, 0xF7, 0xE1, 0xF8
_0810936A:
	bl func_08108650
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0xE4, 0x5F, 0x03, 0x02
	thumb_func_start mode_mapinspect_2
mode_mapinspect_2: @ 08109378
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	ldr r0, _081094BC @ =0x02035E4C
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, _081094C0 @ =0x02035E50
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, _081094C4 @ =0x02035E78
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, _081094C8 @ =0x02035E70
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, _081094CC @ =0x02035F54
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, _081094D0 @ =0x02035F70
	ldr r0, [r0, #0x00]
	bl func_080028C0
	movs r0, #0x00
	mov r8, r0
	ldr r0, _081094D4 @ =0x02035EA0
	mov r9, r0
	movs r7, #0x00
_081093BA:
	mov r0, r9
	adds r5, r7, r0
	adds r4, r7, #0x0
	movs r6, #0x02
_081093C2:
	ldr r0, [r5, #0x00]
	cmp r0, #0x00
	beq _081093CC
	bl func_08002C10
_081093CC:
	ldr r0, _081094D8 @ =0x02035ED0
	adds r0, r4, r0
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _081093DA
	bl func_080028C0
_081093DA:
	adds r5, #0x04
	adds r4, #0x04
	subs r6, #0x01
	cmp r6, #0x00
	bge _081093C2
	adds r7, #0x0C
	movs r0, #0x01
	add r8, r0
	mov r0, r8
	cmp r0, #0x03
	ble _081093BA
	ldr r0, _081094DC @ =0x02035F3C
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _081093FC
	bl func_08002C10
_081093FC:
	ldr r0, _081094E0 @ =0x02035F40
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08109408
	bl func_080028C0
_08109408:
	ldr r0, _081094E4 @ =0x02035F48
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08109414
	bl func_08002C10
_08109414:
	ldr r0, _081094E8 @ =0x02035F4C
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08109420
	bl func_080028C0
_08109420:
	ldr r0, _081094EC @ =0x02035E74
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0810942C
	bl func_08002C10
_0810942C:
	ldr r4, _081094F0 @ =0x02035F94
	ldr r0, [r4, #0x00]
	movs r1, #0x24
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl func_080009C4
	ldr r4, _081094F4 @ =0x02035F9C
	ldr r0, [r4, #0x00]
	movs r1, #0x5A
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl func_080009C4
	ldr r4, _081094F8 @ =0x02035FA4
	ldr r0, [r4, #0x00]
	ldr r1, _081094FC @ =0x02035FAA
	ldrh r1, [r1, #0x00]
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl func_080009C4
	ldr r4, _08109500 @ =0x02035FAC
	ldr r0, [r4, #0x00]
	ldr r1, _08109504 @ =0x02035FB2
	ldrh r1, [r1, #0x00]
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl func_080009C4
	ldr r4, _08109508 @ =0x02035FB4
	ldr r0, [r4, #0x00]
	ldr r1, _0810950C @ =0x02035FBA
	ldrh r1, [r1, #0x00]
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl func_080009C4
	ldr r5, _08109510 @ =0x02035FBC
	ldr r4, _08109514 @ =0x02035FC2
	movs r0, #0x00
	mov r8, r0
_0810948A:
	ldr r0, [r5, #0x00]
	ldrh r1, [r4, #0x00]
	bl func_08065AE0
	ldm r5!, {r0}
	bl func_080009C4
	adds r4, #0x02
	movs r0, #0x01
	negs r0, r0
	add r8, r0
	mov r0, r8
	cmp r0, #0x00
	bge _0810948A
	ldr r0, _08109518 @ =0x02035E28
	ldr r0, [r0, #0x00]
	bl func_080009C4
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_081094BC: .4byte 0x02035E4C
_081094C0: .4byte 0x02035E50
_081094C4: .4byte 0x02035E78
_081094C8: .4byte 0x02035E70
_081094CC: .4byte 0x02035F54
_081094D0: .4byte 0x02035F70
_081094D4: .4byte 0x02035EA0
_081094D8: .4byte 0x02035ED0
_081094DC: .4byte 0x02035F3C
_081094E0: .4byte 0x02035F40
_081094E4: .4byte 0x02035F48
_081094E8: .4byte 0x02035F4C
_081094EC: .4byte 0x02035E74
_081094F0: .4byte 0x02035F94
_081094F4: .4byte 0x02035F9C
_081094F8: .4byte 0x02035FA4
_081094FC: .4byte 0x02035FAA
_08109500: .4byte 0x02035FAC
_08109504: .4byte 0x02035FB2
_08109508: .4byte 0x02035FB4
_0810950C: .4byte 0x02035FBA
_08109510: .4byte 0x02035FBC
_08109514: .4byte 0x02035FC2
_08109518: .4byte 0x02035E28

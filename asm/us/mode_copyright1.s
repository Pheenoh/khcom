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

	thumb_func_start mode_copyright1_0
mode_copyright1_0: @ 080D7014
	push {r4, lr}
	cmp r0, #0x00
	bne _080D7024
	ldr r1, _080D7020 @ =0x02034ED4
	movs r0, #0x01
	b _080D7028
_080D7020: .4byte 0x02034ED4
_080D7024:
	ldr r1, _080D70FC @ =0x02034ED4
	movs r0, #0x00
_080D7028:
	strb r0, [r1, #0x00]
	ldr r4, _080D7100 @ =0x02034ED8
	movs r0, #0x00
	strb r0, [r4, #0x00]
	bl func_08008BBC
	cmp r0, #0x01
	bne _080D705A
	strb r0, [r4, #0x00]
	bl func_08008B40
	bl func_08008DCC
	movs r0, #0x00
	bl func_08009088
	movs r0, #0x01
	bl func_08009088
	movs r0, #0x00
	bl func_08009418
	movs r0, #0x01
	bl func_08009418
_080D705A:
	movs r0, #0x00
	bl func_08009150
	cmp r0, #0x01
	bne _080D706C
	strb r0, [r4, #0x00]
	movs r0, #0x00
	bl func_08009088
_080D706C:
	movs r0, #0x01
	bl func_08009150
	cmp r0, #0x01
	bne _080D707E
	strb r0, [r4, #0x00]
	movs r0, #0x01
	bl func_08009088
_080D707E:
	movs r0, #0x00
	bl func_080094EC
	cmp r0, #0x01
	bne _080D7090
	strb r0, [r4, #0x00]
	movs r0, #0x00
	bl func_08009418
_080D7090:
	movs r0, #0x01
	bl func_080094EC
	cmp r0, #0x01
	bne _080D70A2
	strb r0, [r4, #0x00]
	movs r0, #0x01
	bl func_08009418
_080D70A2:
	bl func_08008E58
	cmp r0, #0x01
	bne _080D70B0
	strb r0, [r4, #0x00]
	bl func_08008DCC
_080D70B0:
	movs r0, #0x00
	bl func_0811FE70
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x1F
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x00
	movs r1, #0x03
	bl func_080055C8
	ldr r0, _080D70FC @ =0x02034ED4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D7114
	ldr r1, _080D7104 @ =0x09801DD8
	ldr r2, _080D7108 @ =0x00004FC0
	movs r0, #0x00
	bl func_080050B8
	ldr r1, _080D710C @ =0x0984B298
	movs r2, #0xE0
	lsls r2, r2, #0x01
	movs r0, #0x00
	bl func_080050DC
	ldr r1, _080D7110 @ =0x09849098
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_0800510C
	b _080D7136
	.byte 0x00, 0x00
_080D70FC: .4byte 0x02034ED4
_080D7100: .4byte 0x02034ED8
_080D7104: .4byte 0x09801DD8
_080D7108: .4byte 0x00004FC0
_080D710C: .4byte 0x0984B298
_080D7110: .4byte 0x09849098
_080D7114:
	ldr r1, _080D714C @ =0x097DB5F8
	ldr r2, _080D7150 @ =0x00004FC0
	movs r0, #0x00
	bl func_080050B8
	ldr r1, _080D7154 @ =0x0984AA38
	movs r2, #0x80
	lsls r2, r2, #0x02
	movs r0, #0x00
	bl func_080050DC
	ldr r1, _080D7158 @ =0x09841798
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_0800510C
_080D7136:
	movs r0, #0x01
	movs r1, #0x43
	bl func_08006120
	ldr r1, _080D715C @ =0x02034ED6
	movs r0, #0x3C
	strh r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D714C: .4byte 0x097DB5F8
_080D7150: .4byte 0x00004FC0
_080D7154: .4byte 0x0984AA38
_080D7158: .4byte 0x09841798
_080D715C: .4byte 0x02034ED6
	thumb_func_start mode_copyright1_1
mode_copyright1_1: @ 080D7160
	push {lr}
	ldr r0, _080D7174 @ =0x02034ED8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D717C
	ldr r0, _080D7178 @ =0x09EF6AF0
	movs r1, #0x00
	bl func_080010CC
	b _080D71CC
_080D7174: .4byte 0x02034ED8
_080D7178: .4byte 0x09EF6AF0
_080D717C:
	bl func_08006314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D71CC
	ldr r1, _080D71A4 @ =0x02034ED6
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080D71A8
	subs r0, #0x01
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080D71CC
	movs r0, #0x01
	movs r1, #0x43
	bl func_08006184
	b _080D71CC
	.byte 0x00, 0x00
_080D71A4: .4byte 0x02034ED6
_080D71A8:
	ldr r0, _080D71BC @ =0x02034ED4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D71C4
	ldr r0, _080D71C0 @ =0x09EF4EC0
	movs r1, #0x01
	bl func_080010CC
	b _080D71CC
	.byte 0x00, 0x00
_080D71BC: .4byte 0x02034ED4
_080D71C0: .4byte 0x09EF4EC0
_080D71C4:
	ldr r0, _080D71D0 @ =0x09EF4ED0
	movs r1, #0x01
	bl func_080010CC
_080D71CC:
	pop {r0}
	bx r0
_080D71D0: .4byte 0x09EF4ED0
	thumb_func_start mode_copyright1_2
mode_copyright1_2: @ 080D71D4
	bx lr
	.byte 0x00, 0x00

.syntax unified
	.align 2, 0
	.global task_sroll_a_name_1
	.thumb
	.thumb_func
	.type task_sroll_a_name_1, %function
task_sroll_a_name_1: @ 08114874
	push {r4, lr}
	adds r1, r0, #0x0
	ldrh r0, [r1, #0x04]
	adds r2, r0, #0x1
	movs r3, #0x00
	strh r2, [r1, #0x04]
	movs r4, #0x02
	ldsh r0, [r1, r4]
	cmp r0, #0x02
	bne _081148C4
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x2F
	bgt _081148A4
	ldr r4, _081148A0 @ =0x03007564
	movs r2, #0x04
	ldsh r0, [r1, r2]
	movs r1, #0x03
	bl func_0811D5EC
	strh r0, [r4, #0x00]
	b _081148CC
_081148A0: .4byte 0x03007564
_081148A4:
	cmp r0, #0x30
	bne _081148B0
	ldr r0, _081148BC @ =0x03007554
	strh r3, [r0, #0x00]
	ldr r0, _081148C0 @ =0x03007564
	strh r3, [r0, #0x00]
_081148B0:
	adds r0, r1, #0x0
	adds r0, #0x20
	bl func_08005A64
	b _081148CC
	.byte 0x00, 0x00
_081148BC: .4byte 0x03007554
_081148C0: .4byte 0x03007564
_081148C4:
	adds r0, r1, #0x0
	adds r0, #0x20
	bl func_08005A64
_081148CC:
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
.syntax divided

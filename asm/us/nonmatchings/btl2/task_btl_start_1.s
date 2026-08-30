.syntax unified
	.align 2, 0
	.global task_btl_start_1
	.thumb
	.thumb_func
	.type task_btl_start_1, %function
task_btl_start_1: @ 08031B64
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x14
	bgt _08031B78
	movs r0, #0x00
	movs r1, #0x28
	bl func_08006120
_08031B78:
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x2B
	beq _08031BA8
	cmp r0, #0x2B
	bgt _08031B8A
	cmp r0, #0x22
	beq _08031B90
	b _08031BB6
_08031B8A:
	cmp r0, #0x4A
	beq _08031BB2
	b _08031BB6
_08031B90:
	movs r1, #0x80
	lsls r1, r1, #0x01
	ldr r0, _08031BA4 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x10]
	ldr r3, [r0, #0x14]
	movs r0, #0x23
	bl func_08019050
	b _08031BB6
_08031BA4: .4byte 0x02039B84
_08031BA8:
	movs r0, #0x02
	movs r1, #0x1E
	bl func_08006120
	b _08031BB6
_08031BB2:
	movs r0, #0x00
	b _08031BBE
_08031BB6:
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
	movs r0, #0x01
_08031BBE:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided

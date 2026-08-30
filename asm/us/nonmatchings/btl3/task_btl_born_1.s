.syntax unified
	.align 2, 0
	.global task_btl_born_1
	.thumb
	.thumb_func
	.type task_btl_born_1, %function
task_btl_born_1: @ 08040080
	push {r4, r5, lr}
	adds r4, r0, #0x0
	bl func_080128EC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08040148
	adds r1, r4, #0x4
	movs r2, #0x18
	negs r2, r2
	movs r3, #0x0C
	negs r3, r3
	adds r0, r4, #0x0
	bl func_0801A8A4
	ldr r5, _080400CC @ =0x0000022D
	adds r0, r5, #0x0
	bl func_08008974
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080400B2
	adds r0, r5, #0x0
	bl func_0811FE70
_080400B2:
	ldrh r0, [r4, #0x12]
	bl func_08003A98
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080400D4
	ldr r0, _080400D0 @ =0x02039B84
	ldr r1, [r0, #0x00]
	movs r0, #0x90
	lsls r0, r0, #0x01
	adds r1, r1, r0
	b _080400EA
	.byte 0x00, 0x00
_080400CC: .4byte 0x0000022D
_080400D0: .4byte 0x02039B84
_080400D4:
	movs r0, #0x01
	bl func_08003B24
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080400F8
	ldr r0, _080400F4 @ =0x02039B84
	ldr r1, [r0, #0x00]
	movs r3, #0x90
	lsls r3, r3, #0x01
	adds r1, r1, r3
_080400EA:
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
	movs r0, #0x00
	b _0804014A
_080400F4: .4byte 0x02039B84
_080400F8:
	ldrh r1, [r4, #0x10]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0804011C
	ldr r0, [r4, #0x00]
	ldr r1, [r4, #0x04]
	ldr r2, [r4, #0x08]
	ldr r3, _08040118 @ =0xFFFFF000
	adds r2, r2, r3
	movs r3, #0x80
	lsls r3, r3, #0x02
	bl func_08013EDC
	b _0804012E
	.byte 0x00, 0x00
_08040118: .4byte 0xFFFFF000
_0804011C:
	ldr r0, [r4, #0x00]
	ldr r1, [r4, #0x04]
	ldr r2, [r4, #0x08]
	ldr r3, _08040140 @ =0xFFFFF800
	adds r2, r2, r3
	movs r3, #0x80
	lsls r3, r3, #0x01
	bl func_08013EDC
_0804012E:
	ldr r0, _08040144 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x2C
	ldr r1, [r4, #0x0C]
	adds r2, r4, #0x0
	bl func_08000E14
	movs r0, #0x00
	b _0804014A
_08040140: .4byte 0xFFFFF800
_08040144: .4byte 0x02039B84
_08040148:
	movs r0, #0x01
_0804014A:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided

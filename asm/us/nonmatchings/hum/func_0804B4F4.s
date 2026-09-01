.syntax unified
	.align 2, 0
	.global func_0804B4F4
	.thumb
	.thumb_func
	.type func_0804B4F4, %function
func_0804B4F4: @ 0804B4F4
	push {r4, r5, r6, lr}
	add sp, #-0x008
	adds r4, r0, #0x0
	ldr r5, _0804B54C @ =0x02039B84
	ldr r0, [r5, #0x00]
	ldr r6, [r0, #0x7C]
	adds r0, r4, #0x0
	adds r0, #0x40
	add r2, sp, #0x004
	mov r1, sp
	movs r3, #0x00
	bl func_0801C700
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_0800F368
	movs r3, #0x80
	lsls r3, r3, #0x01
	adds r0, r4, #0x0
	adds r1, r3, #0x0
	adds r2, r3, #0x0
	bl func_0800F504
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0804B59A
	ldr r0, [r5, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x08
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0804B550
	subs r1, #0x63
	movs r2, #0xA0
	lsls r2, r2, #0x02
	adds r0, r4, #0x0
	bl func_0804B44C
	b _0804B596
_0804B54C: .4byte 0x02039B84
_0804B550:
	bl GetRandom
	movs r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _0804B588
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0804B574
	ldr r1, [sp, #0x000]
	movs r0, #0xA0
	lsls r0, r0, #0x06
	b _0804B578
_0804B574:
	ldr r1, [sp, #0x000]
	ldr r0, _0804B584 @ =0xFFFFD800
_0804B578:
	adds r1, r1, r0
	ldr r2, [sp, #0x004]
	adds r0, r4, #0x0
	bl func_0804B4BC
	b _0804B596
_0804B584: .4byte 0xFFFFD800
_0804B588:
	movs r1, #0x50
	negs r1, r1
	movs r2, #0xA0
	lsls r2, r2, #0x03
	adds r0, r4, #0x0
	bl func_0804B44C
_0804B596:
	movs r0, #0x01
	b _0804B59C
_0804B59A:
	movs r0, #0x00
_0804B59C:
	add sp, #0x008
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided

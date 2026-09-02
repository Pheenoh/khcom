.syntax unified
	.align 2, 0
	.global func_0807B478
	.thumb
	.thumb_func
	.type func_0807B478, %function
func_0807B478: @ 0807B478
	push {r4, r5, r6, r7, lr}
	mov r12, r0
	ldr r3, _0807B4B4 @ =0x02039B84
	ldr r4, [r3, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	movs r2, #0x90
	lsls r2, r2, #0x07
	movs r5, #0x00
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	adds r6, r3, #0x0
	cmp r0, #0x00
	beq _0807B548
	ldr r0, _0807B4B8 @ =0x02039B9C
	ldr r1, [r0, #0x00]
	adds r1, #0xF4
	ldr r1, [r1, #0x00]
	adds r7, r0, #0x0
	cmp r1, #0x29
	beq _0807B4C0
	adds r2, r4, #0x0
	adds r2, #0xF4
	ldr r1, _0807B4BC @ =0x02039DD4
	ldr r0, [r1, #0x00]
	adds r0, #0xCC
	ldrh r0, [r0, #0x00]
	str r0, [r2, #0x00]
	b _0807B4CE
_0807B4B4: .4byte 0x02039B84
_0807B4B8: .4byte 0x02039B9C
_0807B4BC: .4byte 0x02039DD4
_0807B4C0:
	adds r0, r4, #0x0
	adds r0, #0xF4
	str r5, [r0, #0x00]
	ldr r1, _0807B520 @ =0x02039DD4
	ldr r0, [r1, #0x00]
	adds r0, #0xCC
	strh r5, [r0, #0x00]
_0807B4CE:
	adds r5, r1, #0x0
	ldr r3, [r6, #0x00]
	adds r4, r3, #0x0
	adds r4, #0xF4
	ldr r0, [r4, #0x00]
	cmp r0, #0x29
	bne _0807B4F8
	ldr r0, [r5, #0x00]
	adds r0, #0xCE
	movs r2, #0x00
	strh r2, [r0, #0x00]
	ldr r0, [r7, #0x00]
	adds r1, r0, #0x0
	adds r1, #0xF4
	str r2, [r1, #0x00]
	adds r0, #0xF8
	strh r2, [r0, #0x00]
	str r2, [r4, #0x00]
	adds r0, r3, #0x0
	adds r0, #0xF8
	strh r2, [r0, #0x00]
_0807B4F8:
	ldr r1, [r5, #0x00]
	adds r4, r1, #0x0
	adds r4, #0xCC
	ldrh r0, [r4, #0x00]
	cmp r0, #0x2D
	bne _0807B530
	ldr r0, [r7, #0x00]
	adds r0, #0xF4
	ldr r2, [r0, #0x00]
	cmp r2, #0x00
	beq _0807B524
	ldr r0, [r6, #0x00]
	adds r0, #0xF4
	str r2, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xCE
	ldrh r0, [r0, #0x00]
	strh r0, [r4, #0x00]
	b _0807B530
	.byte 0x00, 0x00
_0807B520: .4byte 0x02039DD4
_0807B524:
	ldr r0, [r6, #0x00]
	adds r0, #0xF4
	str r2, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xCE
	strh r2, [r0, #0x00]
_0807B530:
	ldr r0, [r6, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x2F
	bne _0807B570
	mov r0, r12
	adds r0, #0x9C
	movs r1, #0x02
	strh r1, [r0, #0x00]
	adds r0, #0x02
	strh r1, [r0, #0x00]
	b _0807B570
_0807B548:
	ldr r0, _0807B564 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0xCC
	ldrh r1, [r0, #0x00]
	cmp r1, #0x29
	beq _0807B568
	cmp r1, #0x2D
	beq _0807B568
	adds r1, r4, #0x0
	adds r1, #0xF4
	ldrh r0, [r0, #0x00]
	str r0, [r1, #0x00]
	b _0807B570
	.byte 0x00, 0x00
_0807B564: .4byte 0x02039DD4
_0807B568:
	ldr r0, [r6, #0x00]
	adds r0, #0xF4
	movs r1, #0x00
	str r1, [r0, #0x00]
_0807B570:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided

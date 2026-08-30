.syntax unified
	.align 2, 0
	.global func_0801071C
	.thumb
	.thumb_func
	.type func_0801071C, %function
func_0801071C: @ 0801071C
	push {r4, r5, r6, lr}
	add sp, #-0x008
	movs r4, #0x00
	str r4, [sp, #0x000]
	ldr r5, _080107A0 @ =0x02039B84
	ldr r1, [r5, #0x00]
	ldr r6, _080107A4 @ =0x05000074
	mov r0, sp
	adds r2, r6, #0x0
	bl func_08117FE8
	str r4, [sp, #0x004]
	add r0, sp, #0x004
	ldr r1, _080107A8 @ =0x02039B9C
	ldr r1, [r1, #0x00]
	adds r2, r6, #0x0
	bl func_08117FE8
	ldr r2, [r5, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xA0
	str r4, [r0, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xFC
	ldr r0, _080107AC @ =0xFFFF0000
	str r0, [r1, #0x00]
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r1, r2, r0
	movs r0, #0x42
	str r0, [r1, #0x00]
	adds r1, r2, #0x0
	adds r1, #0xB3
	movs r0, #0x0A
	strb r0, [r1, #0x00]
	ldr r5, [r5, #0x00]
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x6C]
	ldr r2, _080107B0 @ =0x00004000
	ldr r3, _080107B4 @ =0x00000000
	orrs r0, r2
	str r0, [r5, #0x68]
	str r1, [r5, #0x6C]
	ldr r3, _080107B8 @ =0x020348CC
	strh r4, [r3, #0x00]
	ldr r2, _080107BC @ =0x020348D0
	strh r4, [r2, #0x00]
	ldr r1, _080107C0 @ =0x020348D4
	strh r4, [r1, #0x00]
	ldr r0, _080107C4 @ =0x020348D8
	strh r4, [r0, #0x00]
	strh r4, [r3, #0x02]
	strh r4, [r2, #0x02]
	strh r4, [r1, #0x02]
	strh r4, [r0, #0x02]
	ldr r0, _080107C8 @ =0x020348DC
	strh r4, [r0, #0x00]
	strh r4, [r0, #0x02]
	ldr r0, _080107CC @ =0x020348E0
	strh r4, [r0, #0x00]
	ldr r0, _080107D0 @ =0x020348E2
	strh r4, [r0, #0x00]
	add sp, #0x008
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080107A0: .4byte 0x02039B84
_080107A4: .4byte 0x05000074
_080107A8: .4byte 0x02039B9C
_080107AC: .4byte 0xFFFF0000
_080107B0: .4byte 0x00004000
_080107B4: .4byte 0x00000000
_080107B8: .4byte 0x020348CC
_080107BC: .4byte 0x020348D0
_080107C0: .4byte 0x020348D4
_080107C4: .4byte 0x020348D8
_080107C8: .4byte 0x020348DC
_080107CC: .4byte 0x020348E0
_080107D0: .4byte 0x020348E2
.syntax divided

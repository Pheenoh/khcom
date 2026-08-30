.syntax unified
	.align 2, 0
	.global func_080C5A3C
	.thumb
	.thumb_func
	.type func_080C5A3C, %function
func_080C5A3C: @ 080C5A3C
	push {r4, r5, lr}
	lsls r2, r2, #0x18
	ldr r4, _080C5A7C @ =0x0203C3B0
	movs r3, #0xF0
	lsls r3, r3, #0x14
	ands r3, r2
	lsrs r3, r3, #0x18
	ldr r5, _080C5A80 @ =0x0000C1F0
	adds r2, r5, #0x0
	orrs r3, r2
	strh r3, [r4, #0x00]
	ldr r2, _080C5A84 @ =0x0203C3A0
	movs r3, #0x00
	strb r3, [r2, #0x00]
	ldr r2, _080C5A88 @ =0x0203C3A8
	strb r3, [r2, #0x00]
	ldr r2, _080C5A8C @ =0x0203C38C
	strb r3, [r2, #0x00]
	ldr r2, _080C5A90 @ =0x0203C3AC
	str r0, [r2, #0x00]
	ldr r0, _080C5A94 @ =0x0203BEAC
	str r1, [r0, #0x00]
	ldr r1, _080C5A98 @ =0x0203BEA4
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r1, _080C5A9C @ =0x02039B68
	ldr r0, _080C5AA0 @ =0x0000DDDD
	strh r0, [r1, #0x00]
	strh r0, [r1, #0x02]
	pop {r4, r5}
	pop {r0}
	bx r0
_080C5A7C: .4byte 0x0203C3B0
_080C5A80: .4byte 0x0000C1F0
_080C5A84: .4byte 0x0203C3A0
_080C5A88: .4byte 0x0203C3A8
_080C5A8C: .4byte 0x0203C38C
_080C5A90: .4byte 0x0203C3AC
_080C5A94: .4byte 0x0203BEAC
_080C5A98: .4byte 0x0203BEA4
_080C5A9C: .4byte 0x02039B68
_080C5AA0: .4byte 0x0000DDDD
.syntax divided

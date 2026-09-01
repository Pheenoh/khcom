.syntax unified
	.align 2, 0
	.global func_080E03C0
	.thumb
	.thumb_func
	.type func_080E03C0, %function
func_080E03C0: @ 080E03C0
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_080A42C8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080E03F2
	ldr r0, _080E03F8 @ =0x02039BA0
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x70]
	ldr r1, _080E03FC @ =0x00841000
	ands r0, r1
	cmp r0, #0x00
	bne _080E03F2
	ldr r0, _080E0400 @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	movs r1, #0x84
	ands r0, r1
	cmp r0, #0x00
	bne _080E03F2
	ldr r1, [r2, #0x20]
	ldr r0, [r2, #0x24]
	cmp r1, r0
	beq _080E0404
_080E03F2:
	movs r0, #0x00
	b _080E0410
	.byte 0x00, 0x00
_080E03F8: .4byte 0x02039BA0
_080E03FC: .4byte 0x00841000
_080E0400: .4byte 0x0203C7AC
_080E0404:
	movs r1, #0x00
	ldr r0, [r2, #0x68]
	cmp r0, r4
	bne _080E040E
	movs r1, #0x01
_080E040E:
	adds r0, r1, #0x0
_080E0410:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

.syntax unified
	.align 2, 0
	.global func_080E2BA0
	.thumb
	.thumb_func
	.type func_080E2BA0, %function
func_080E2BA0: @ 080E2BA0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080E2BCC @ =0x02034F20
	ldr r3, [r0, #0x00]
	ldr r0, _080E2BD0 @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x00]
	movs r2, #0x90
	lsls r2, r2, #0x14
	ands r1, r2
	movs r0, #0x80
	lsls r0, r0, #0x14
	cmp r1, r0
	beq _080E2BDE
	cmp r1, r0
	bhi _080E2BD4
	movs r0, #0x80
	lsls r0, r0, #0x11
	cmp r1, r0
	beq _080E2BDA
	b _080E2BE2
_080E2BCC: .4byte 0x02034F20
_080E2BD0: .4byte 0x0203C7AC
_080E2BD4:
	cmp r1, r2
	beq _080E2BE4
	b _080E2BE2
_080E2BDA:
	movs r4, #0x00
	b _080E2BE4
_080E2BDE:
	movs r4, #0x03
	b _080E2BE4
_080E2BE2:
	movs r4, #0x05
_080E2BE4:
	cmp r4, #0x05
	beq _080E2BF0
	adds r0, r3, #0x0
	adds r1, r4, #0x0
	bl func_080E2668
_080E2BF0:
	adds r0, r4, #0x0
	pop {r4}
	pop {r1}
	bx r1
.syntax divided

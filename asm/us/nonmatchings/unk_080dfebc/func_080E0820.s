.syntax unified
	.align 2, 0
	.global func_080E0820
	.thumb
	.thumb_func
	.type func_080E0820, %function
func_080E0820: @ 080E0820
	push {r4, lr}
	ldr r4, _080E0870 @ =0x02039BA0
	ldr r0, [r4, #0x00]
	adds r0, #0x78
	bl TaskPoolDraw
	ldr r0, _080E0874 @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x05
	ands r0, r1
	cmp r0, #0x00
	bne _080E0844
	ldr r0, [r4, #0x00]
	adds r0, #0x8C
	bl TaskPoolDraw
_080E0844:
	ldr r2, [r4, #0x00]
	ldr r0, [r2, #0x70]
	movs r1, #0x80
	lsls r1, r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _080E085A
	adds r0, r2, #0x0
	adds r0, #0xB4
	bl TaskPoolDraw
_080E085A:
	ldr r0, [r4, #0x00]
	adds r0, #0xA0
	bl TaskPoolDraw
	ldr r0, [r4, #0x00]
	adds r0, #0xC8
	bl TaskPoolDraw
	pop {r4}
	pop {r0}
	bx r0
_080E0870: .4byte 0x02039BA0
_080E0874: .4byte 0x0203C7AC
.syntax divided

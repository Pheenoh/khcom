.syntax unified
	.align 2, 0
	.global func_080E0878
	.thumb
	.thumb_func
	.type func_080E0878, %function
func_080E0878: @ 080E0878
	push {r4, lr}
	ldr r4, _080E08B4 @ =0x02039BA0
	ldr r0, [r4, #0x00]
	adds r0, #0x78
	bl TaskPoolDestroy
	ldr r0, [r4, #0x00]
	adds r0, #0x8C
	bl TaskPoolDestroy
	ldr r0, [r4, #0x00]
	adds r0, #0xA0
	bl TaskPoolDestroy
	ldr r0, [r4, #0x00]
	adds r0, #0xC8
	bl TaskPoolDestroy
	ldr r0, [r4, #0x00]
	adds r0, #0xB4
	bl TaskPoolDestroy
	ldr r0, _080E08B8 @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	adds r0, #0x30
	bl TaskPoolDestroy
	pop {r4}
	pop {r0}
	bx r0
_080E08B4: .4byte 0x02039BA0
_080E08B8: .4byte 0x0203C7AC
.syntax divided

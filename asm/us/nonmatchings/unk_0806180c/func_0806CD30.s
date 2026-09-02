.syntax unified
	.align 2, 0
	.global func_0806CD30
	.thumb
	.thumb_func
	.type func_0806CD30, %function
func_0806CD30: @ 0806CD30
	push {lr}
	cmp r0, #0x00
	beq _0806CD3C
	cmp r0, #0x01
	beq _0806CD4C
	b _0806CD56
_0806CD3C:
	ldr r1, _0806CD48 @ =0x096145D8
	movs r0, #0x00
	movs r2, #0x40
	bl LoadBgPalette
	b _0806CD56
_0806CD48: .4byte 0x096145D8
_0806CD4C:
	ldr r1, _0806CD5C @ =0x09614618
	movs r0, #0x00
	movs r2, #0x40
	bl LoadBgPalette
_0806CD56:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0806CD5C: .4byte 0x09614618
.syntax divided

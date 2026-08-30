.syntax unified
	.align 2, 0
	.global func_080D4D1C
	.thumb
	.thumb_func
	.type func_080D4D1C, %function
func_080D4D1C: @ 080D4D1C
	push {lr}
	ldr r0, _080D4D38 @ =0x0203C460
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D4D32
	ldr r0, [r0, #0x28]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D4D3C
_080D4D32:
	movs r0, #0x00
	b _080D4D3E
	.byte 0x00, 0x00
_080D4D38: .4byte 0x0203C460
_080D4D3C:
	movs r0, #0x01
_080D4D3E:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

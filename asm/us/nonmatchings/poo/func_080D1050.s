.syntax unified
	.align 2, 0
	.global func_080D1050
	.thumb
	.thumb_func
	.type func_080D1050, %function
func_080D1050: @ 080D1050
	push {lr}
	movs r0, #0x02
	bl func_080D2D50
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D1070
	ldr r0, _080D106C @ =0x02034E30
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x08]
	cmp r0, #0x00
	beq _080D1070
	movs r0, #0x01
	b _080D1072
_080D106C: .4byte 0x02034E30
_080D1070:
	movs r0, #0x00
_080D1072:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

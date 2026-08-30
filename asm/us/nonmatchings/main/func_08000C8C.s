.syntax unified
	.align 2, 0
	.global func_08000C8C
	.thumb
	.thumb_func
	.type func_08000C8C, %function
func_08000C8C: @ 08000C8C
	push {lr}
	ldr r2, [r0, #0x08]
	cmp r2, #0x00
	beq _08000CAA
	ldrh r1, [r2, #0x0C]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _08000CA6
	adds r0, r2, #0x0
	bl func_08000CD4
	b _08000CAC
_08000CA6:
	ldr r0, [r2, #0x00]
	b _08000CAC
_08000CAA:
	movs r0, #0x00
_08000CAC:
	pop {r1}
	bx r1
.syntax divided

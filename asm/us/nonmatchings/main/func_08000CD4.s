.syntax unified
	.align 2, 0
	.global func_08000CD4
	.thumb
	.thumb_func
	.type func_08000CD4, %function
func_08000CD4: @ 08000CD4
	ldr r2, [r0, #0x08]
	cmp r2, #0x00
	beq _08000CEC
	ldrh r1, [r2, #0x0C]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _08000CE8
	adds r0, r2, #0x0
	b func_08000CD4
_08000CE8:
	ldr r0, [r2, #0x00]
	b _08000CEE
_08000CEC:
	movs r0, #0x00
_08000CEE:
	bx lr
.syntax divided

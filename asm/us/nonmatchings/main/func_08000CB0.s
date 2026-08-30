.syntax unified
	.align 2, 0
	.global func_08000CB0
	.thumb
	.thumb_func
	.type func_08000CB0, %function
func_08000CB0: @ 08000CB0
	push {lr}
	ldr r2, [r0, #0x0C]
	cmp r2, #0x00
	beq _08000CCE
	ldrh r1, [r2, #0x0C]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _08000CCA
	adds r0, r2, #0x0
	bl func_08000CF0
	b _08000CD0
_08000CCA:
	ldr r0, [r2, #0x00]
	b _08000CD0
_08000CCE:
	movs r0, #0x00
_08000CD0:
	pop {r1}
	bx r1
.syntax divided

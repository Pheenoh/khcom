.syntax unified
	.align 2, 0
	.global func_080FBA4C
	.thumb
	.thumb_func
	.type func_080FBA4C, %function
func_080FBA4C: @ 080FBA4C
	push {r4, lr}
	adds r3, r0, #0x0
	movs r0, #0xD2
	lsls r0, r0, #0x01
	adds r2, r3, r0
	ldrh r0, [r2, #0x0C]
	subs r0, #0x01
	strh r0, [r2, #0x0C]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bge _080FBA96
	ldrh r0, [r2, #0x0A]
	adds r0, #0x01
	strh r0, [r2, #0x0A]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r4, #0x08
	ldsh r1, [r2, r4]
	cmp r0, r1
	blt _080FBA78
	movs r0, #0x00
	strh r0, [r2, #0x0A]
_080FBA78:
	movs r1, #0x0A
	ldsh r0, [r2, r1]
	ldr r1, [r2, #0x04]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldrh r0, [r0, #0x02]
	strh r0, [r2, #0x0C]
	movs r4, #0x0A
	ldsh r0, [r2, r4]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldrh r1, [r0, #0x00]
	adds r0, r3, #0x0
	bl func_080FB930
_080FBA96:
	pop {r4}
	pop {r0}
	bx r0
.syntax divided

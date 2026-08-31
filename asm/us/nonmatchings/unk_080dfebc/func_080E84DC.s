.syntax unified
	.align 2, 0
	.global func_080E84DC
	.thumb
	.thumb_func
	.type func_080E84DC, %function
func_080E84DC: @ 080E84DC
	push {r4, lr}
	adds r4, r0, #0x0
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080E8518 @ =0x00002710
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _080E851C @ =0x000005DB
	cmp r1, r0
	bhi _080E8520
	ldr r1, [r4, #0x00]
	ldr r2, [r4, #0x04]
	ldr r3, [r4, #0x08]
	movs r0, #0x00
	bl func_080E8FB8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _080E8530
	ldr r0, [r4, #0x00]
	ldr r1, [r4, #0x04]
	ldr r2, [r4, #0x08]
	bl func_080E83DC
	b _080E8530
_080E8518: .4byte 0x00002710
_080E851C: .4byte 0x000005DB
_080E8520:
	ldr r0, _080E8538 @ =0x00001D4B
	cmp r1, r0
	bhi _080E8530
	ldr r0, [r4, #0x00]
	ldr r1, [r4, #0x04]
	ldr r2, [r4, #0x08]
	bl func_080E83DC
_080E8530:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080E8538: .4byte 0x00001D4B
.syntax divided

.syntax unified
	.align 2, 0
	.global func_080CE880
	.thumb
	.thumb_func
	.type func_080CE880, %function
func_080CE880: @ 080CE880
	ldr r1, _080CE8B0 @ =0x096FD59C
	ldrh r0, [r0, #0x26]
	lsls r0, r0, #0x04
	adds r0, r0, r1
	ldrh r1, [r0, #0x0C]
	ldr r0, [r0, #0x00]
	lsls r1, r1, #0x02
	adds r1, r1, r0
	ldr r1, [r1, #0x00]
	movs r3, #0x00
	ldrh r0, [r1, #0x04]
	cmp r3, r0
	bge _080CE8AC
	adds r2, r0, #0x0
_080CE89C:
	ldrh r0, [r1, #0x08]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r1, #0x04
	subs r2, #0x01
	cmp r2, #0x00
	bne _080CE89C
_080CE8AC:
	adds r0, r3, #0x0
	bx lr
_080CE8B0: .4byte 0x096FD59C
.syntax divided
